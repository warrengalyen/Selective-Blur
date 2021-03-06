#include "Utility.h"

void Calc(unsigned short *Hist, int Intensity, unsigned char *&Pixel, int Threshold)
{
	int Low, High, Sum = 0, Weight = 0;
	Low = Intensity - Threshold;
	High = Intensity + Threshold;
	if (Low < 0) Low = 0;
	if (High > 255) High = 255;
	for (int i = Low; i <= High; i++)
	{
		Weight += Hist[i];
		Sum += Hist[i] * i;
	}
	if (Weight != 0) *Pixel = Sum / Weight;
}

/// <summary>
/// Selective image blur effect, O (1) complexity
/// </summary>
/// <param name="Src">The data matrix of the source image to be processed.</param>
/// <param name="Dest">The data matrix of the result image to be processed.</param>
/// <param name="Radius">Specify the size of the fuzzy sampling area, valid range [1, 127].</param>
/// <param name="Threshold">The option controls how much the adjacent pixel hue value differs from 
///   the central pixel value to be blurred. Pixels with tonal values ​​less than the threshold value
///   are excluded. The effective range [2, 255].</param>
IP_RET __stdcall SelectiveBlur(TMatrix *Src, TMatrix *Dest, int Radius, int Threshold, EdgeMode Edge)
{
	if (Src == NULL || Dest == NULL) return IP_RET_ERR_NULLREFERENCE;
	if (Src->Data == NULL || Dest->Data == NULL) return IP_RET_ERR_NULLREFERENCE;
	if (Src->Width != Dest->Width || Src->Height != Dest->Height || Src->Channel != Dest->Channel || Src->Depth != Dest->Depth || Src->WidthStep != Dest->WidthStep) return IP_RET_ERR_PARAMISMATCH;
	if (Src->Depth != IP_DEPTH_8U || Dest->Depth != IP_DEPTH_8U) return IP_RET_ERR_NOTSUPPORTED;
	if (Radius < 0 || Radius >= 127 || Threshold < 2 || Threshold > 255) return IP_RET_ERR_ARGUMENTOUTOFRANGE;

	IP_RET Ret = IP_RET_OK;

	if (Src->Data == Dest->Data)
	{
		TMatrix *Clone = NULL;
		Ret = IP_CloneMatrix(Src, &Clone);
		if (Ret != IP_RET_OK) return Ret;
		Ret = SelectiveBlur(Clone, Dest, Radius, Threshold, Edge);
		IP_FreeMatrix(&Clone);
		return Ret;
	}
	if (Src->Channel == 1)
	{
		TMatrix *Row = NULL, *Col = NULL;
		unsigned char *LinePS, *LinePD;
		int X, Y, K, Width = Src->Width, Height = Src->Height;
		int *RowOffset, *ColOffset;

		unsigned short *Hist = NULL;
		unsigned short *ColHist = (unsigned short *)IP_AllocMemory(256 * (Width + 2 * Radius) * sizeof(unsigned short), true);
		if (ColHist == NULL)
		{
			Ret = IP_RET_ERR_OUTOFMEMORY;
			goto Done8; 
		}
		Hist = (unsigned short *)IP_AllocMemory(256 * sizeof(unsigned short), true);
		if (Hist == NULL)
		{
			Ret = IP_RET_ERR_OUTOFMEMORY;
			goto Done8;
		}

		Ret = GetValidCoordinate(Width, Height, Radius, Radius, Radius, Radius, Edge, &Row, &Col);		// Get the coordinate offset
		if (Ret != IP_RET_OK) goto Done8;

		ColHist += Radius * 256;
		RowOffset = ((int *)Row->Data) + Radius;
		ColOffset = ((int *)Col->Data) + Radius;		    	

		for (Y = 0; Y < Height; Y++)
		{
			if (Y == 0)
			{
				for (int K = -Radius; K <= Radius; K++)
				{
					LinePS = Src->Data + ColOffset[K] * Src->WidthStep;
					for (X = -Radius; X < Width + Radius; X++)
					{
						ColHist[X * 256 + LinePS[RowOffset[X]]]++;
					}
				}
			}
			else												
			{
				LinePS = Src->Data + ColOffset[Y - Radius - 1] * Src->WidthStep;
				for (X = -Radius; X < Width + Radius; X++)		// Delete the histogram data for the line that moved out of range
				{
					ColHist[X * 256 + LinePS[RowOffset[X]]]--;
				}

				LinePS = Src->Data + ColOffset[Y + Radius] * Src->WidthStep;
				for (X = -Radius; X < Width + Radius; X++)		// Increase the histogram data of the line in the entry
				{
					ColHist[X * 256 + LinePS[RowOffset[X]]]++;
				}
			}

			memset(Hist, 0, 256 * sizeof(unsigned short));		//	Each row of histogram data is zeroed first

			LinePS = Src->Data + Y * Src->WidthStep;
			LinePD = Dest->Data + Y * Dest->WidthStep;

			for (X = 0; X < Width; X++)
			{
				if (X == 0)
				{
					for (K = -Radius; K <= Radius; K++)			// The first pixel in the line needs to be recalculated
						HistogramAddShort(ColHist + K * 256, Hist);
				}
				else
				{
					/*	HistgramAddShort(ColHist + RowOffset[X + Radius] * 256, Hist);
					HistogramSubShort(ColHist + RowOffset[X - Radius - 1] * 256, Hist);
					*/
					HistogramSubAddShort(ColHist + RowOffset[X - Radius - 1] * 256, ColHist + RowOffset[X + Radius] * 256, Hist);  //	The other pixels in the line can be deleted and added in turn
				}
				Calc(Hist, LinePS[0], LinePD, Threshold);

				LinePS++;
				LinePD++;
			}
		}
		ColHist -= Radius * 256;   // Offset recovery
	Done8:
		IP_FreeMatrix(&Row);
		IP_FreeMatrix(&Col);
		IP_FreeMemory(ColHist);
		IP_FreeMemory(Hist);

		return Ret;
	}
	else
	{
		TMatrix *Blue = NULL, *Green = NULL, *Red = NULL, *Alpha = NULL;
		IP_RET Ret = SplitRGBA(Src, &Blue, &Green, &Red, &Alpha);
		if (Ret != IP_RET_OK) goto Done24;
		Ret = SelectiveBlur(Blue, Blue, Radius, Threshold, Edge);
		if (Ret != IP_RET_OK) goto Done24;
		Ret = SelectiveBlur(Green, Green, Radius, Threshold, Edge);
		if (Ret != IP_RET_OK) goto Done24;
		Ret = SelectiveBlur(Red, Red, Radius, Threshold, Edge);
		if (Ret != IP_RET_OK) goto Done24;											//	The 32 bit Alpha does not do anything, in fact, the 32 bit related algorithms are basically non-channel processing.
		Ret = CombineRGBA(Dest, Blue, Green, Red, Alpha);
	Done24:
		IP_FreeMatrix(&Blue);
		IP_FreeMatrix(&Green);
		IP_FreeMatrix(&Red);
		IP_FreeMatrix(&Alpha);
		return Ret;
	}
}


 