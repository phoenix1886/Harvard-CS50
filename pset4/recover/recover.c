#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef uint8_t BYTE;

int BUFFERSIZE = 512;

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }

    FILE* forensic_image = fopen(argv[1], "r");
    if (forensic_image == NULL){
        fprintf(stderr, "Unable to open forensic image");
        return 2;
    }

    int fileNumber = 0;
    FILE* currentFile = NULL;
    BYTE buffer[BUFFERSIZE];
    while (fread(buffer, sizeof(BYTE), BUFFERSIZE, forensic_image)){
        if (currentFile != NULL || fileNumber == 0){
            if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                buffer[3] >= 224 &&
                buffer[3] <= 239){
                if (currentFile != NULL) fclose(currentFile);
                char filename[8];
                sprintf(filename, "%03d.jpg", fileNumber);
                currentFile = fopen(filename, "w");
                fileNumber++;
            }
            if (currentFile != NULL){
                fwrite(buffer, sizeof(BYTE) * BUFFERSIZE, 1, currentFile);
            }
        }
        memset(buffer, 0, BUFFERSIZE*sizeof(BYTE));
    }
    fclose(forensic_image);
    if (currentFile != NULL) fclose(currentFile);
    return 0;
}