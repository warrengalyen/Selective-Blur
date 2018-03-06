#include "stdafx.h"

#define WIDTHBYTES(bytes)  (((bytes * 8) + 31) / 32 * 4)

unsigned char ClampToByte(int Value);
void HistogramAddShort(unsigned short *X, unsigned short *Y);
void HistogramSubShort(unsigned short *X, unsigned short *Y);
void HistogramSubAddShort(unsigned short *X, unsigned short *Y, unsigned short *Z);
IP_RET GetValidCoordinate(int Width, int Height, int Left, int Right, int Top, int Bottom, EdgeMode Edge,
	TMatrix **Row, TMatrix **Col);
IP_RET SplitRGBA(TMatrix *Src, TMatrix **Blue, TMatrix **Green, TMatrix **Red, TMatrix **Alpha);
IP_RET CombineRGBA(TMatrix *Src, TMatrix *Blue, TMatrix *Green, TMatrix *Red, TMatrix *Alpha);
