#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]){
    if(argc!=2){
        printf("Usage: ./caeser k\n");
        return 1;
    }
    int i=0;
    while(argv[1][i]!='\0'){
        if(!(isalpha(argv[1][i]))){
            printf("Usage: ./caeser k\n");
            return 1;
        }
        i++;
    }
    int vig_length=strlen(argv[1]);
    int vigenere[vig_length];
    for(int j=0; j<vig_length; j++){
        if(argv[1][j]<92){
            vigenere[j]=argv[1][j]-65;
//            printf("%d\t%c\n", vigenere[j], argv[1][j]);
        }
        else{
            vigenere[j]=argv[1][j]-97;
//            printf("%d\t%c\n", vigenere[j], argv[1][j]);
        }
    }
    printf("plaintext: ");
    string p=get_string();
    printf("ciphertext: ");
    int counter=0;
    for(int k=0, n=strlen(p); k<n; k++){
        if(isalpha(p[k])){
            if(p[k]<92){
//                printf("%c\t%d\t%c\n", p[k], vigenere[counter], 65+(p[k]-65+vigenere[counter])%26);
                printf("%c", 65+(p[k]-65+vigenere[counter])%26);
            }
            else{
//                printf("%c\t%d\t%c\n", p[k], vigenere[counter], 97+(p[k]-97+vigenere[counter])%26);
                printf("%c", 97+(p[k]-97+vigenere[counter])%26);
            }
            counter=(counter+1)%vig_length;
        }
        else{
            printf("%c", p[k]);
        }
    }
    printf("\n");
    return 0;
}