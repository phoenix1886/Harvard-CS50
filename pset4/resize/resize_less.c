// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

RGBTRIPLE* multiply_line(RGBTRIPLE* line, int width, int n);


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];



    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER initial_bf;
    fread(&initial_bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPFILEHEADER result_bf;
    memcpy(&result_bf, &initial_bf, sizeof(initial_bf));

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER initial_bi;
    fread(&initial_bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    BITMAPINFOHEADER result_bi;
    memcpy(&result_bi, &initial_bi, sizeof(initial_bi));

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (initial_bf.bfType != 0x4d42
        || initial_bf.bfOffBits != 54
        || initial_bi.biSize != 40
        || initial_bi.biBitCount != 24
        || initial_bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int initial_padding = (4 - (initial_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    result_bi.biWidth = initial_bi.biWidth * n;
    result_bi.biHeight = initial_bi.biHeight * n;
    int result_padding = (4 - (result_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    result_bi.biSizeImage = (result_bi.biWidth*sizeof(RGBTRIPLE) + result_padding) * abs(result_bi.biHeight);
    result_bf.bfSize = sizeof(result_bf) + sizeof(result_bi) + result_bi.biSizeImage;


    // write outfile's BITMAPFILEHEADER
    fwrite(&result_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&result_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines

    //BYTE* line = malloc(result_bi.biWidth * sizeof(RGBTRIPLE) + result_padding);
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(initial_bi.biHeight); i < biHeight; i++)
    {
        RGBTRIPLE* line = malloc(initial_bi.biWidth);
        fread(line, sizeof(RGBTRIPLE), initial_bi.biWidth, inptr);

        RGBTRIPLE* mult_line = multiply_line(line, initial_bi.biWidth, n);
        for (int j = 0; j < n; j++){
            fwrite(mult_line, sizeof(RGBTRIPLE), initial_bi.biWidth*n, outptr);
            for (int k = 0; k < result_padding; k++){
                fputc(0x00, outptr);
            }
        }

        fseek(inptr, initial_padding, SEEK_CUR);
        free(mult_line);
        free(line);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

RGBTRIPLE* multiply_line(RGBTRIPLE* line, int width, int n){
    RGBTRIPLE* result_line = malloc(n*width*sizeof(RGBTRIPLE));
    for (int i=0; i<width; i++){
        RGBTRIPLE triple = line[i];
        for (int j=0; j < n; j++){
            result_line[(i*n+j)] = triple;
        }
    }
    return result_line;
}