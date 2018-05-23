#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_alphabetic(char c);

int main(int argc, string argv[]){
    if (argc != 2) {
        printf("Error");
        return 0;
    }
    int offset = atoi(argv[1]);
    string text = get_string("Enter text to cipher: ");

    int ord_a = (int)'a';
    int ord_z = (int)'z';
    int ord_A = (int)'A';
    int ord_Z = (int)'Z';
    int alpha_length = ord_z - ord_a + 1;

    for (int i = 0; i < strlen(text); i++){
        char current_char = text[i];
        int ord_ch = (int)current_char;

        if (isalpha(current_char) && islower(current_char)){
            ord_ch += offset;
            if (ord_ch < ord_a){
                ord_ch += alpha_length;
            } else if( ord_ch > ord_z) {
                ord_ch -= alpha_length;
            }
        }
        else if (isalpha(current_char) && isupper(current_char)){
            ord_ch += offset;
            if (ord_ch < ord_A){
                ord_ch += alpha_length;
            } else if( ord_ch > ord_Z) {
                ord_ch -= alpha_length;
            }
        }
        printf("%c", (char)ord_ch);
    }
}

int is_alphabetic(char c){
    if (c >= 'A' && c <= 'z'){
        return 1;
    } else {
        return 0;
    }
}




