#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int all_A(char* word){
    for (int i = 0; i< strlen(word); i++){
        if (word[i] != 'A'){
            return 0;
        }
    }
    return 1;
}

char* change_char(char* str, int index, char ch){
    char* res = (char *) malloc(strlen(str)+1);
    for (int i = 0; i <= strlen(str); i++){
        if (i != index){
            res[i] = str[i];
        } else {
            res[i] = ch;
        }
        //printf("%c - %c\n", str[i], res[i] );
    }
    return res;
}

char* generate_string(char* word){

    int len = strlen(word);

    for (int i = len-1; i >= 0; i++){
        if (word[i] == 'z'){
            word = change_char(word, i ,'A');
        }
        else {
            if (word[i] == 'Z'){
                word[i] = 'a';
            }

            //word[i] = (char)((int)word[i]+1);
            //printf("%s", "here");
            word = change_char(word, i, (char)((int)word[i]+1));

            break;
        }
    }
    if (all_A(word) == 1){
        word = strcat("B", word);
    }
    return word;
}

int main(){


    printf("%s\n", generate_string("abz"));
    printf("%s\n", generate_string("azz"));
    printf("%s\n", generate_string("aZz"));
}
