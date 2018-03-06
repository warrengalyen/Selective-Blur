#include "Utility.h"

unsigned char ClampToByte(int Value)
{
	return ((Value | ((signed int)(255 - Value) >> 31)) & ~((signed int)Value >> 31));
}

/// <summary>
/// Add unsigned short integer histogram data, Y = X + Y
/// </summary>
/// <param name="X">Added to result</param>
/// <param name="Y">The number is added, the result is saved here.</param>
/// <remarks>Using SSE optimization</remarks>
void HistogramAddShort(unsigned short *X, unsigned short *Y)
{
	*(__m128i*)(Y + 0) = _mm_add_epi16(*(__m128i*)&Y[0], *(__m128i*)&X[0]);		
	*(__m128i*)(Y + 8) = _mm_add_epi16(*(__m128i*)&Y[8], *(__m128i*)&X[8]);
	*(__m128i*)(Y + 16) = _mm_add_epi16(*(__m128i*)&Y[16], *(__m128i*)&X[16]);
	*(__m128i*)(Y + 24) = _mm_add_epi16(*(__m128i*)&Y[24], *(__m128i*)&X[24]);
	*(__m128i*)(Y + 32) = _mm_add_epi16(*(__m128i*)&Y[32], *(__m128i*)&X[32]);
	*(__m128i*)(Y + 40) = _mm_add_epi16(*(__m128i*)&Y[40], *(__m128i*)&X[40]);
	*(__m128i*)(Y + 48) = _mm_add_epi16(*(__m128i*)&Y[48], *(__m128i*)&X[48]);
	*(__m128i*)(Y + 56) = _mm_add_epi16(*(__m128i*)&Y[56], *(__m128i*)&X[56]);
	*(__m128i*)(Y + 64) = _mm_add_epi16(*(__m128i*)&Y[64], *(__m128i*)&X[64]);
	*(__m128i*)(Y + 72) = _mm_add_epi16(*(__m128i*)&Y[72], *(__m128i*)&X[72]);
	*(__m128i*)(Y + 80) = _mm_add_epi16(*(__m128i*)&Y[80], *(__m128i*)&X[80]);
	*(__m128i*)(Y + 88) = _mm_add_epi16(*(__m128i*)&Y[88], *(__m128i*)&X[88]);
	*(__m128i*)(Y + 96) = _mm_add_epi16(*(__m128i*)&Y[96], *(__m128i*)&X[96]);
	*(__m128i*)(Y + 104) = _mm_add_epi16(*(__m128i*)&Y[104], *(__m128i*)&X[104]);
	*(__m128i*)(Y + 112) = _mm_add_epi16(*(__m128i*)&Y[112], *(__m128i*)&X[112]);
	*(__m128i*)(Y + 120) = _mm_add_epi16(*(__m128i*)&Y[120], *(__m128i*)&X[120]);
	*(__m128i*)(Y + 128) = _mm_add_epi16(*(__m128i*)&Y[128], *(__m128i*)&X[128]);
	*(__m128i*)(Y + 136) = _mm_add_epi16(*(__m128i*)&Y[136], *(__m128i*)&X[136]);
	*(__m128i*)(Y + 144) = _mm_add_epi16(*(__m128i*)&Y[144], *(__m128i*)&X[144]);
	*(__m128i*)(Y + 152) = _mm_add_epi16(*(__m128i*)&Y[152], *(__m128i*)&X[152]);
	*(__m128i*)(Y + 160) = _mm_add_epi16(*(__m128i*)&Y[160], *(__m128i*)&X[160]);
	*(__m128i*)(Y + 168) = _mm_add_epi16(*(__m128i*)&Y[168], *(__m128i*)&X[168]);
	*(__m128i*)(Y + 176) = _mm_add_epi16(*(__m128i*)&Y[176], *(__m128i*)&X[176]);
	*(__m128i*)(Y + 184) = _mm_add_epi16(*(__m128i*)&Y[184], *(__m128i*)&X[184]);
	*(__m128i*)(Y + 192) = _mm_add_epi16(*(__m128i*)&Y[192], *(__m128i*)&X[192]);
	*(__m128i*)(Y + 200) = _mm_add_epi16(*(__m128i*)&Y[200], *(__m128i*)&X[200]);
	*(__m128i*)(Y + 208) = _mm_add_epi16(*(__m128i*)&Y[208], *(__m128i*)&X[208]);
	*(__m128i*)(Y + 216) = _mm_add_epi16(*(__m128i*)&Y[216], *(__m128i*)&X[216]);
	*(__m128i*)(Y + 224) = _mm_add_epi16(*(__m128i*)&Y[224], *(__m128i*)&X[224]);
	*(__m128i*)(Y + 232) = _mm_add_epi16(*(__m128i*)&Y[232], *(__m128i*)&X[232]);
	*(__m128i*)(Y + 240) = _mm_add_epi16(*(__m128i*)&Y[240], *(__m128i*)&X[240]);
	*(__m128i*)(Y + 248) = _mm_add_epi16(*(__m128i*)&Y[248], *(__m128i*)&X[248]);
}

/// <summary>
/// Subtract unsigned short integer histogram data, Y = Y + X
/// </summary>
/// <param name="X">Subtracted value</param>
/// <param name="Y">The number is subtracted, the result is saved here.</param>
/// <remarks>Using SSE optimization</remarks>
void HistogramSubShort(unsigned short *X, unsigned short *Y)
{
	*(__m128i*)(Y + 0) = _mm_sub_epi16(*(__m128i*)&Y[0], *(__m128i*)&X[0]);
	*(__m128i*)(Y + 8) = _mm_sub_epi16(*(__m128i*)&Y[8], *(__m128i*)&X[8]);
	*(__m128i*)(Y + 16) = _mm_sub_epi16(*(__m128i*)&Y[16], *(__m128i*)&X[16]);
	*(__m128i*)(Y + 24) = _mm_sub_epi16(*(__m128i*)&Y[24], *(__m128i*)&X[24]);
	*(__m128i*)(Y + 32) = _mm_sub_epi16(*(__m128i*)&Y[32], *(__m128i*)&X[32]);
	*(__m128i*)(Y + 40) = _mm_sub_epi16(*(__m128i*)&Y[40], *(__m128i*)&X[40]);
	*(__m128i*)(Y + 48) = _mm_sub_epi16(*(__m128i*)&Y[48], *(__m128i*)&X[48]);
	*(__m128i*)(Y + 56) = _mm_sub_epi16(*(__m128i*)&Y[56], *(__m128i*)&X[56]);
	*(__m128i*)(Y + 64) = _mm_sub_epi16(*(__m128i*)&Y[64], *(__m128i*)&X[64]);
	*(__m128i*)(Y + 72) = _mm_sub_epi16(*(__m128i*)&Y[72], *(__m128i*)&X[72]);
	*(__m128i*)(Y + 80) = _mm_sub_epi16(*(__m128i*)&Y[80], *(__m128i*)&X[80]);
	*(__m128i*)(Y + 88) = _mm_sub_epi16(*(__m128i*)&Y[88], *(__m128i*)&X[88]);
	*(__m128i*)(Y + 96) = _mm_sub_epi16(*(__m128i*)&Y[96], *(__m128i*)&X[96]);
	*(__m128i*)(Y + 104) = _mm_sub_epi16(*(__m128i*)&Y[104], *(__m128i*)&X[104]);
	*(__m128i*)(Y + 112) = _mm_sub_epi16(*(__m128i*)&Y[112], *(__m128i*)&X[112]);
	*(__m128i*)(Y + 120) = _mm_sub_epi16(*(__m128i*)&Y[120], *(__m128i*)&X[120]);
	*(__m128i*)(Y + 128) = _mm_sub_epi16(*(__m128i*)&Y[128], *(__m128i*)&X[128]);
	*(__m128i*)(Y + 136) = _mm_sub_epi16(*(__m128i*)&Y[136], *(__m128i*)&X[136]);
	*(__m128i*)(Y + 144) = _mm_sub_epi16(*(__m128i*)&Y[144], *(__m128i*)&X[144]);
	*(__m128i*)(Y + 152) = _mm_sub_epi16(*(__m128i*)&Y[152], *(__m128i*)&X[152]);
	*(__m128i*)(Y + 160) = _mm_sub_epi16(*(__m128i*)&Y[160], *(__m128i*)&X[160]);
	*(__m128i*)(Y + 168) = _mm_sub_epi16(*(__m128i*)&Y[168], *(__m128i*)&X[168]);
	*(__m128i*)(Y + 176) = _mm_sub_epi16(*(__m128i*)&Y[176], *(__m128i*)&X[176]);
	*(__m128i*)(Y + 184) = _mm_sub_epi16(*(__m128i*)&Y[184], *(__m128i*)&X[184]);
	*(__m128i*)(Y + 192) = _mm_sub_epi16(*(__m128i*)&Y[192], *(__m128i*)&X[192]);
	*(__m128i*)(Y + 200) = _mm_sub_epi16(*(__m128i*)&Y[200], *(__m128i*)&X[200]);
	*(__m128i*)(Y + 208) = _mm_sub_epi16(*(__m128i*)&Y[208], *(__m128i*)&X[208]);
	*(__m128i*)(Y + 216) = _mm_sub_epi16(*(__m128i*)&Y[216], *(__m128i*)&X[216]);
	*(__m128i*)(Y + 224) = _mm_sub_epi16(*(__m128i*)&Y[224], *(__m128i*)&X[224]);
	*(__m128i*)(Y + 232) = _mm_sub_epi16(*(__m128i*)&Y[232], *(__m128i*)&X[232]);
	*(__m128i*)(Y + 240) = _mm_sub_epi16(*(__m128i*)&Y[240], *(__m128i*)&X[240]);
	*(__m128i*)(Y + 248) = _mm_sub_epi16(*(__m128i*)&Y[248], *(__m128i*)&X[248]);
}

/// <summary>
/// Unsigned short integer histogram data is added and subtracted, Z = Z + Y - X
/// </summary>
/// <param name="X">Minus value</param>
/// <param name="Y">Addition value</param>
/// <param name="Z"></param>
/// <remarks>Using SSE optimization</remarks>
void HistogramSubAddShort(unsigned short *X, unsigned short *Y, unsigned short *Z)
{
	*(__m128i*)(Z + 0) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[0], *(__m128i*)&Z[0]), *(__m128i*)&X[0]);
	*(__m128i*)(Z + 8) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[8], *(__m128i*)&Z[8]), *(__m128i*)&X[8]);
	*(__m128i*)(Z + 16) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[16], *(__m128i*)&Z[16]), *(__m128i*)&X[16]);
	*(__m128i*)(Z + 24) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[24], *(__m128i*)&Z[24]), *(__m128i*)&X[24]);
	*(__m128i*)(Z + 32) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[32], *(__m128i*)&Z[32]), *(__m128i*)&X[32]);
	*(__m128i*)(Z + 40) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[40], *(__m128i*)&Z[40]), *(__m128i*)&X[40]);
	*(__m128i*)(Z + 48) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[48], *(__m128i*)&Z[48]), *(__m128i*)&X[48]);
	*(__m128i*)(Z + 56) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[56], *(__m128i*)&Z[56]), *(__m128i*)&X[56]);
	*(__m128i*)(Z + 64) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[64], *(__m128i*)&Z[64]), *(__m128i*)&X[64]);
	*(__m128i*)(Z + 72) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[72], *(__m128i*)&Z[72]), *(__m128i*)&X[72]);
	*(__m128i*)(Z + 80) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[80], *(__m128i*)&Z[80]), *(__m128i*)&X[80]);
	*(__m128i*)(Z + 88) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[88], *(__m128i*)&Z[88]), *(__m128i*)&X[88]);
	*(__m128i*)(Z + 96) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[96], *(__m128i*)&Z[96]), *(__m128i*)&X[96]);
	*(__m128i*)(Z + 104) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[104], *(__m128i*)&Z[104]), *(__m128i*)&X[104]);
	*(__m128i*)(Z + 112) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[112], *(__m128i*)&Z[112]), *(__m128i*)&X[112]);
	*(__m128i*)(Z + 120) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[120], *(__m128i*)&Z[120]), *(__m128i*)&X[120]);
	*(__m128i*)(Z + 128) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[128], *(__m128i*)&Z[128]), *(__m128i*)&X[128]);
	*(__m128i*)(Z + 136) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[136], *(__m128i*)&Z[136]), *(__m128i*)&X[136]);
	*(__m128i*)(Z + 144) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[144], *(__m128i*)&Z[144]), *(__m128i*)&X[144]);
	*(__m128i*)(Z + 152) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[152], *(__m128i*)&Z[152]), *(__m128i*)&X[152]);
	*(__m128i*)(Z + 160) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[160], *(__m128i*)&Z[160]), *(__m128i*)&X[160]);
	*(__m128i*)(Z + 168) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[168], *(__m128i*)&Z[168]), *(__m128i*)&X[168]);
	*(__m128i*)(Z + 176) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[176], *(__m128i*)&Z[176]), *(__m128i*)&X[176]);
	*(__m128i*)(Z + 184) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[184], *(__m128i*)&Z[184]), *(__m128i*)&X[184]);
	*(__m128i*)(Z + 192) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[192], *(__m128i*)&Z[192]), *(__m128i*)&X[192]);
	*(__m128i*)(Z + 200) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[200], *(__m128i*)&Z[200]), *(__m128i*)&X[200]);
	*(__m128i*)(Z + 208) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[208], *(__m128i*)&Z[208]), *(__m128i*)&X[208]);
	*(__m128i*)(Z + 216) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[216], *(__m128i*)&Z[216]), *(__m128i*)&X[216]);
	*(__m128i*)(Z + 224) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[224], *(__m128i*)&Z[224]), *(__m128i*)&X[224]);
	*(__m128i*)(Z + 232) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[232], *(__m128i*)&Z[232]), *(__m128i*)&X[232]);
	*(__m128i*)(Z + 240) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[240], *(__m128i*)&Z[240]), *(__m128i*)&X[240]);
	*(__m128i*)(Z + 248) = _mm_sub_epi16(_mm_add_epi16(*(__m128i*)&Y[248], *(__m128i*)&Z[248]), *(__m128i*)&X[248]);
}

/// <summary>
/// Calculates the rational value of each coordinate after expansion according to the specified edge mode
/// </summary>
/// <param name="Width">The width of the matrix.</param>
/// <param name="Height">The height of the matrix.</param>
/// <param name="Left">The left edge of the coordinates.</param>
/// <param name="Right">The right edge of the coordinates.</param>
/// <param name="Top">The top edge of the coordinates.</param>
/// <param name="Bottom">The bottom edge of the coordinates.</param>
/// <param name="Edge">The method to deal with the edge.</param>
/// <param name="Row">The coordinates of the row.</param>
/// <param name="Col">The coordinates of the column.</param>
/// <returns>Returns whether the function is successful.</returns>
IP_RET GetValidCoordinate(int Width, int Height, int Left, int Right, int Top, int Bottom, EdgeMode Edge, TMatrix **Row, TMatrix **Col)
{
	if ((Left < 0) || (Right < 0) || (Top < 0) || (Bottom < 0)) return IP_RET_ERR_ARGUMENTOUTOFRANGE;
	IP_RET Ret = IP_CreateMatrix(Width + Left + Right, 1, IP_DEPTH_32S, 1, Row);
	if (Ret != IP_RET_OK) return Ret;
	Ret = IP_CreateMatrix(1, Height + Top + Bottom, IP_DEPTH_32S, 1, Col);
	if (Ret != IP_RET_OK) return Ret;

	int XX, YY, *RowPos = (int *)(*Row)->Data, *ColPos = (int *)(*Col)->Data;

	for (int X = -Left; X < Width + Right; X++)
	{
		if (X < 0)
		{
			if (Edge == EdgeMode::Tile)						// Repeating edge pixels
				RowPos[X + Left] = 0;
			else
			{
				XX = -X;
				while (XX >= Width) XX -= Width;			// mirror data
				RowPos[X + Left] = XX;
			}
		}
		else if (X >= Width)
		{
			if (Edge == EdgeMode::Tile)
				RowPos[X + Left] = Width - 1;
			else
			{
				XX = Width - (X - Width + 2);
				while (XX < 0) XX += Width;
				RowPos[X + Left] = XX;
			}
		}
		else
		{
			RowPos[X + Left] = X;
		}
	}

	for (int Y = -Top; Y < Height + Bottom; Y++)
	{
		if (Y < 0)
		{
			if (Edge == EdgeMode::Tile)
				ColPos[Y + Top] = 0;
			else
			{
				YY = -Y;
				while (YY >= Height) YY -= Height;
				ColPos[Y + Top] = YY;
			}
		}
		else if (Y >= Height)
		{
			if (Edge == EdgeMode::Tile)
				ColPos[Y + Top] = Height - 1;
			else
			{
				YY = Height - (Y - Height + 2);
				while (YY < 0) YY += Height;
				ColPos[Y + Top] = YY;
			}
		}
		else
		{
			ColPos[Y + Top] = Y;
		}
	}
	return IP_RET_OK;
}

/// <summary>
/// Decomposes a color image into a single channel image of R, G, B and A
/// </summary>
/// <param name="Src">The data structure of the source image that needs to be processed.</param>
/// <param name="Blue">The data matrix of the image's blue channel.</param>
/// <param name="Green">The data matrix of the image's green channel.</param>
/// <param name="Red">The data matrix of the image's red channel.</param>
/// <param name="Alpha">The data matrix of the image's alpha channel.</param>
/// <remarks>With 8 bit parallel processing, the speed can be improved by about 20%.</remarks>
IP_RET SplitRGBA(TMatrix *Src, TMatrix **Blue, TMatrix **Green, TMatrix **Red, TMatrix **Alpha)
{
	if (Src == NULL) return IP_RET_ERR_NULLREFERENCE;
	if (Src->Data == NULL) return IP_RET_ERR_NULLREFERENCE;
	if (Src->Depth != IP_DEPTH_8U) return IP_RET_ERR_NOTSUPPORTED;

	IP_RET Ret;
	Ret = IP_CreateMatrix(Src->Width, Src->Height, Src->Depth, 1, Blue);
	if (Ret != IP_RET_OK) goto Done;
	Ret = IP_CreateMatrix(Src->Width, Src->Height, Src->Depth, 1, Green);
	if (Ret != IP_RET_OK) goto Done;
	Ret = IP_CreateMatrix(Src->Width, Src->Height, Src->Depth, 1, Red);
	if (Ret != IP_RET_OK) goto Done;
	if (Src->Channel == 4)
	{
		Ret = IP_CreateMatrix(Src->Width, Src->Height, Src->Depth, 1, Alpha);
		if (Ret != IP_RET_OK) goto Done;
	}

	int X, Y, Block, Width = Src->Width, Height = Src->Height;
	unsigned char *LinePS, *LinePB, *LinePG, *LinePR, *LinePA;
	const int BlockSize = 8;
	Block = Width / BlockSize;

	if (Src->Channel == 3)
	{
		for (Y = 0; Y < Height; Y++)
		{
			LinePS = Src->Data + Y * Src->WidthStep;
			LinePB = (*Blue)->Data + Y * (*Blue)->WidthStep;
			LinePG = (*Green)->Data + Y * (*Green)->WidthStep;
			LinePR = (*Red)->Data + Y * (*Red)->WidthStep;
			for (X = 0; X < Block * BlockSize; X += BlockSize)			
			{
				LinePB[0] = LinePS[0];		LinePG[0] = LinePS[1];		LinePR[0] = LinePS[2];
				LinePB[1] = LinePS[3];		LinePG[1] = LinePS[4];		LinePR[1] = LinePS[5];
				LinePB[2] = LinePS[6];		LinePG[2] = LinePS[7];		LinePR[2] = LinePS[8];
				LinePB[3] = LinePS[9];		LinePG[3] = LinePS[10];		LinePR[3] = LinePS[11];
				LinePB[4] = LinePS[12];		LinePG[4] = LinePS[13];		LinePR[4] = LinePS[14];
				LinePB[5] = LinePS[15];		LinePG[5] = LinePS[16];		LinePR[5] = LinePS[17];
				LinePB[6] = LinePS[18];		LinePG[6] = LinePS[19];		LinePR[6] = LinePS[20];
				LinePB[7] = LinePS[21];		LinePG[7] = LinePS[22];		LinePR[7] = LinePS[23];
				LinePB += 8;				LinePG += 8;				LinePR += 8;				LinePS += 24;
			}
			while (X < Width)
			{
				LinePB[0] = LinePS[0];		LinePG[0] = LinePS[1];		LinePR[0] = LinePS[2];
				LinePB++;					LinePG++;					LinePR++;					LinePS += 3;
				X++;
			}
		}
	}
	else if (Src->Channel == 4)
	{
		for (int Y = 0; Y < Height; Y++)
		{
			LinePS = Src->Data + Y * Src->WidthStep;
			LinePB = (*Blue)->Data + Y * (*Blue)->WidthStep;
			LinePG = (*Green)->Data + Y * (*Green)->WidthStep;
			LinePR = (*Red)->Data + Y * (*Red)->WidthStep;
			LinePA = (*Alpha)->Data + Y * (*Alpha)->WidthStep;
			for (X = 0; X < Block * BlockSize; X += BlockSize)
			{
				LinePB[0] = LinePS[0];		LinePG[0] = LinePS[1];		LinePR[0] = LinePS[2];		LinePA[0] = LinePS[3];
				LinePB[1] = LinePS[4];		LinePG[1] = LinePS[5];		LinePR[1] = LinePS[6];		LinePA[1] = LinePS[7];
				LinePB[2] = LinePS[8];		LinePG[2] = LinePS[9];		LinePR[2] = LinePS[10];		LinePA[2] = LinePS[11];
				LinePB[3] = LinePS[12];		LinePG[3] = LinePS[13];		LinePR[3] = LinePS[14];		LinePA[3] = LinePS[15];
				LinePB[4] = LinePS[16];		LinePG[4] = LinePS[17];		LinePR[4] = LinePS[18];		LinePA[4] = LinePS[19];
				LinePB[5] = LinePS[20];		LinePG[5] = LinePS[21];		LinePR[5] = LinePS[22];		LinePA[5] = LinePS[23];
				LinePB[6] = LinePS[24];		LinePG[6] = LinePS[25];		LinePR[6] = LinePS[26];		LinePA[6] = LinePS[27];
				LinePB[7] = LinePS[28];		LinePG[7] = LinePS[29];		LinePR[7] = LinePS[30];		LinePA[7] = LinePS[31];
				LinePB += 8;				LinePG += 8;				LinePR += 8;				LinePA += 8;				LinePS += 32;
			}
			while (X < Width)
			{
				LinePB[0] = LinePS[0];		LinePG[0] = LinePS[1];		LinePR[0] = LinePS[2];		LinePA[0] = LinePS[3];
				LinePB++;					LinePG++;					LinePR++;					LinePA++;					LinePS += 4;
				X++;
			}
		}
	}

	return IP_RET_OK;

Done:
	if (*Blue != NULL) IP_FreeMatrix(Blue);
	if (*Green != NULL) IP_FreeMatrix(Green);
	if (*Red != NULL) IP_FreeMatrix(Red);
	if (*Alpha != NULL) IP_FreeMatrix(Alpha);
	return Ret;
}

/// <summary>
/// A single channel image of R, G, B and A is merged into a color image.
/// </summary>
/// <param name="Dest">The data matrix of the merged image.</param>
/// <param name="Blue">The data matrix of the image's blue channel.</param>
/// <param name="Green">The data matrix of the image's green channel.</param>
/// <param name="Red">The data matrix of the image's red channel.</param>
/// <param name="Alpha">The data matrix of the image's alpha channel.</param>
/// <remarks>With 8 bit parallel processing, the speed can be improved by about 20%.</remarks>
IP_RET CombineRGBA(TMatrix *Dest, TMatrix *Blue, TMatrix *Green, TMatrix *Red, TMatrix *Alpha)
{
	if (Dest == NULL || Blue == NULL || Green == NULL || Red == NULL) return IP_RET_ERR_NULLREFERENCE;
	if (Dest->Data == NULL || Blue->Data == NULL || Green->Data == NULL || Red->Data == NULL) return IP_RET_ERR_NULLREFERENCE;
	if ((Dest->Channel != 3 && Dest->Channel != 4) || Blue->Channel != 1 || Green->Channel != 1 || Red->Channel != 1) return IP_RET_ERR_PARAMISMATCH;
	if (Dest->Width != Blue->Width || Dest->Width != Green->Width || Dest->Width != Red->Width || Dest->Width != Blue->Width)  return IP_RET_ERR_PARAMISMATCH;
	if (Dest->Height != Blue->Height || Dest->Height != Green->Height || Dest->Height != Red->Height || Dest->Height != Blue->Height)  return IP_RET_ERR_PARAMISMATCH;

	if (Dest->Channel == 4)
	{
		if (Alpha == NULL) return IP_RET_ERR_NULLREFERENCE;
		if (Alpha->Data == NULL) return IP_RET_ERR_NULLREFERENCE;
		if (Alpha->Channel != 1) return IP_RET_ERR_PARAMISMATCH;
		if (Dest->Width != Alpha->Width || Dest->Height != Alpha->Height) return IP_RET_ERR_PARAMISMATCH;
	}

	int X, Block, Width = Dest->Width, Height = Dest->Height;
	unsigned char *LinePD, *LinePB, *LinePG, *LinePR, *LinePA;
	const int BlockSize = 8;
	Block = Width / BlockSize;						

	if (Dest->Channel == 3)
	{
		for (int Y = 0; Y < Height; Y++)
		{
			LinePD = Dest->Data + Y * Dest->WidthStep;
			LinePB = Blue->Data + Y * Blue->WidthStep;
			LinePG = Green->Data + Y * Green->WidthStep;
			LinePR = Red->Data + Y * Red->WidthStep;
			for (X = 0; X < Block * BlockSize; X += BlockSize)
			{
				LinePD[0] = LinePB[0];		LinePD[1] = LinePG[0];		LinePD[2] = LinePR[0];
				LinePD[3] = LinePB[1];		LinePD[4] = LinePG[1];		LinePD[5] = LinePR[1];
				LinePD[6] = LinePB[2];		LinePD[7] = LinePG[2];		LinePD[8] = LinePR[2];
				LinePD[9] = LinePB[3];		LinePD[10] = LinePG[3];		LinePD[11] = LinePR[3];
				LinePD[12] = LinePB[4];		LinePD[13] = LinePG[4];		LinePD[14] = LinePR[4];
				LinePD[15] = LinePB[5];		LinePD[16] = LinePG[5];		LinePD[17] = LinePR[5];
				LinePD[18] = LinePB[6];		LinePD[19] = LinePG[6];		LinePD[20] = LinePR[6];
				LinePD[21] = LinePB[7];		LinePD[22] = LinePG[7];		LinePD[23] = LinePR[7];
				LinePB += 8;				LinePG += 8;				LinePR += 8;				LinePD += 24;
			}
			while (X < Width)
			{
				LinePD[0] = LinePB[0];		LinePD[1] = LinePG[0];		LinePD[2] = LinePR[0];
				LinePB++;					LinePG++;					LinePR++;					LinePD += 3;
				X++;
			}
		}
	}
	else if (Dest->Channel == 4)
	{
		for (int Y = 0; Y < Height; Y++)
		{
			LinePD = Dest->Data + Y * Dest->WidthStep;
			LinePB = Blue->Data + Y * Blue->WidthStep;
			LinePG = Green->Data + Y * Green->WidthStep;
			LinePR = Red->Data + Y * Red->WidthStep;
			LinePA = Alpha->Data + Y * Alpha->WidthStep;
			for (X = 0; X < Block * BlockSize; X += BlockSize)
			{
				LinePD[0] = LinePB[0];		LinePD[1] = LinePG[0];		LinePD[2] = LinePR[0];		LinePD[3] = LinePA[0];
				LinePD[4] = LinePB[1];		LinePD[5] = LinePG[1];		LinePD[6] = LinePR[1];		LinePD[7] = LinePA[1];
				LinePD[8] = LinePB[2];		LinePD[9] = LinePG[2];		LinePD[10] = LinePR[2];		LinePD[11] = LinePA[2];
				LinePD[12] = LinePB[3];		LinePD[13] = LinePG[3];		LinePD[14] = LinePR[3];		LinePD[15] = LinePA[3];
				LinePD[16] = LinePB[4];		LinePD[17] = LinePG[4];		LinePD[18] = LinePR[4];		LinePD[19] = LinePA[4];
				LinePD[20] = LinePB[5];		LinePD[21] = LinePG[5];		LinePD[22] = LinePR[5];		LinePD[23] = LinePA[5];
				LinePD[24] = LinePB[6];		LinePD[25] = LinePG[6];		LinePD[26] = LinePR[6];		LinePD[27] = LinePA[6];
				LinePD[28] = LinePB[7];		LinePD[29] = LinePG[7];		LinePD[30] = LinePR[7];		LinePD[31] = LinePA[7];
				LinePB += 8;				LinePG += 8;				LinePR += 8;				LinePA += 8;				LinePD += 32;
			}
			while (X < Width)
			{
				LinePD[0] = LinePB[0];		LinePD[1] = LinePG[0];		LinePD[2] = LinePR[0];		LinePD[3] = LinePA[0];
				LinePB++;					LinePG++;					LinePD++;					LinePA++;					LinePD += 4;
				X++;
			}
		}
	}
	return IP_RET_OK;
}