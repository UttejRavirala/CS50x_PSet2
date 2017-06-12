#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void){
    char *name=get_string();
    int i=0;
    while(name[i] ==' ' && name[i]!='\0'){
        i++;
    }
    while(name[i]!='\0'){
        printf("%c", toupper(name[i]));
        i++;
        while(name[i]!=' ' && name[i]!='\0'){
            i++;
        }
        while(name[i] ==' ' && name[i]!='\0'){
            i++;
        }
    }
    printf("\n");
}