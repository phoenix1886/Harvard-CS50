// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

RGBTRIPLE* multiply_line(RGBTRIPLE* line, int width, double n);
void print_triple(RGBTRIPLE* line, int length);


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    double n = atof(argv[1]);
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

    result_bi.biWidth = (int)(initial_bi.biWidth * n);
    result_bi.biHeight = (int)(initial_bi.biHeight * n);
    printf("Width: %d, Height: %d\n", result_bi.biWidth, result_bi.biHeight);
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

    if (n > 1){
        for (int i = 0, index=0, biHeight = abs(initial_bi.biHeight), new_index=0; i < biHeight; i++)
        {
            RGBTRIPLE* line = malloc(initial_bi.biWidth* sizeof(RGBTRIPLE));
            fread(line, sizeof(RGBTRIPLE), initial_bi.biWidth, inptr);

            RGBTRIPLE* mult_line = multiply_line(line, initial_bi.biWidth, n);
            while (i+1 > (new_index/n) && new_index < abs(result_bi.biHeight)) {
                fwrite(mult_line, sizeof(RGBTRIPLE), result_bi.biWidth, outptr);
                for (int k = 0; k < result_padding; k++){
                    fputc(0x00, outptr);
                }
                new_index++;
            }

            fseek(inptr, initial_padding, SEEK_CUR);

            free(mult_line);
            free(line);
        }
    } else {
        for (int i=0, index=0; index < abs(result_bi.biHeight); i++) {
            RGBTRIPLE *line = malloc(initial_bi.biWidth * sizeof(RGBTRIPLE));
            fread(line, sizeof(RGBTRIPLE), initial_bi.biWidth, inptr);

            if (index == (int)(i * n)) {
                RGBTRIPLE* mult_line = multiply_line(line, initial_bi.biWidth, n);
                fwrite(mult_line, sizeof(RGBTRIPLE), result_bi.biWidth, outptr);
                for (int k = 0; k < result_padding; k++) {
                    fputc(0x00, outptr);
                }
                free(mult_line);
                index++;
            }

            fseek(inptr, initial_padding, SEEK_CUR);

            free(line);
        }
    }

    fclose(inptr);
    fclose(outptr);

    // success
    return 0;
}

RGBTRIPLE* multiply_line(RGBTRIPLE* line, int width, double n){
    int res_width = (int)(n * width);
    //double new_n = (res_width+1) / (width+1);
    RGBTRIPLE* result_line = (RGBTRIPLE*) malloc(res_width*sizeof(RGBTRIPLE));
    if (result_line == NULL){
        printf("no memory");
    }
    //printf("width: %d, n: %d, index: ", width, (int)n);
    int index = 0;
    int i = 0;
    if (n > 1){
        for (i=0; i<width; i++){
            RGBTRIPLE triple = line[i];

            while (i+1 > (index/n) && index < res_width){
                result_line[index] = triple;
                //printf("..%d", index);
                index++;
            }
        }
    } else {
        for (index=0; index<res_width; index++){
            RGBTRIPLE triple = line[i];

            while (index+1 > (i*n) && i < width){
                result_line[index] = triple;
                //printf("..%d", index);
                i++;
            }
        }
    }
    return result_line;
}

void print_triple(RGBTRIPLE* line, int length){
    for (int i = 0; i < length; i++){
        printf(
                "%.2x%.2x%.2x ",
                line[i].rgbtRed,
                line[i].rgbtGreen,
                line[i].rgbtBlue
        );
    }
    printf("\n");
}