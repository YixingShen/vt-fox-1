#ifndef __JPEG_H__
#define __JPEG_H__

#include <stdint.h>
#include <stdbool.h>

typedef unsigned char color;

/*
RGB to YCbCr Conversion:

// Y = 0.299*R + 0.587*G + 0.114*B
inline color RGB2Y(const color r, const color g, const color b)
{
	return (32768 + 19595*r + 38470*g + 7471*b) >> 16;
}
// Cb = 128 - 0.1687*R - 0.3313*G + 0.5*B
inline color RGB2Cb(const color r, const color g, const color b)
{
	return (8421376 - 11058*r - 21709*g + 32767*b) >> 16;
}
// Cr = 128 + 0.5*R - 0.4187*G - 0.0813*B
inline color RGB2Cr(const color r, const color g, const color b)
{
	return (8421376 + 32767*r - 27438*g - 5329*b) >> 16;
}
*/
static int file_jpg;

//---------------- J P E G ---------------

// Application should provide this function for JPEG stream flushing
void write_jpeg(const unsigned char buff[], const unsigned size);

typedef struct huffman_s
{
	const unsigned char  (*haclen)[12];
	const unsigned short (*hacbit)[12];
	const unsigned char  *hdclen;
	const unsigned short *hdcbit;
	const unsigned char  *qtable;
	short                dc;
}
huffman_t;

extern huffman_t huffman_ctx[3];

#define	HUFFMAN_CTX_Y	&huffman_ctx[0]
#define	HUFFMAN_CTX_Cb	&huffman_ctx[1]
#define	HUFFMAN_CTX_Cr	&huffman_ctx[2]

void huffman_start(short height, short width);
void huffman_stop(void);
void huffman_encode(huffman_t *const ctx, const short data[64]);


#endif//__JPEG_H__
