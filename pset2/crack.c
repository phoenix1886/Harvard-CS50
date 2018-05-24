#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>


int all_A(char* word){
    for (int i = 0; i < strlen(word); i++){
        if (word[i] != 'A'){
            return 0;
        }
    }
    return 1;
}


char* change_char(char* str, int index, char ch){
    char* res = malloc(strlen(str)+1);
    for (int i = 0; i <= strlen(str); i++){
        if (i != index){
            res[i] = str[i];
        } else {
            res[i] = ch;
        }
    }
    return res;
}

char* generate_next_password(char word[]){
    int len = strlen(word);

    for (int i = len-1; i >= 0; i--){
        if (word[i] == 'z'){
            word[i] = 'A';
        }
        else {
            if (word[i] == 'Z'){
                word[i] = 'a';
                break;
            }
            else {
                word[i] = (char)((int)word[i]+1);
                break;
            }
        }
    }

    if (all_A(word)){
        char* tmp = malloc(strlen(word) + 2);
        for (int i = 0; i < strlen(word) + 1; i++){
            tmp[i] = 'A';
        }
        strcpy(word, tmp);
    }

    return word;
}


int main(int argc, char* argv[]){
    if (argc < 2){
        return 1;
    }

    char* hash = argv[1];
    char* salt = malloc(3);
    salt[0] = hash[0];
    salt[1] = hash[1];

    char guess_pass[6] = "A";

    while (strlen(guess_pass) < 6){
        char* guess_hash = crypt(guess_pass, salt);
        if (strcmp(guess_hash, hash) == 0){
            printf("password: %s\n", guess_pass);
            return 0;
        }
        strcpy(guess_pass, generate_next_password(guess_pass));
    }
    return 1;
}
