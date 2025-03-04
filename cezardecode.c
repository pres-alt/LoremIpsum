//(str[i] - 'a' + key) % 26 + 'a'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
FILE *fptr;


char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        cipher[i] = (str[i] - 'a' + key) % 26 + 'a';
    }
    cipher[length] = '\0';
    return cipher;
}

char* cezar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    str[length] = '\0';

    return str;
}

int read_cipher(char* filename, char* cipher)
{
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return EXIT_FAILURE;
    }

    fclose(fp);

    return EXIT_SUCCESS;
}


void plain_text(char* text){
    fptr = fopen("plaintext.txt", "w");
    fprintf(fptr, "%s", text);
    fclose(fptr);
}

int main()
{
    char final[MAXN];
    char choice[MAXN];


    while(strcmp(final, "END") != 0){

    printf("Do you want to decode or not? (Y/N): ");
    scanf("%s", choice);


    if(strcmp(choice, "Y") == 0){

    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    char cipher[MAXN];
    if(read_cipher(filename, cipher) == EXIT_SUCCESS)
    {

        printf("Key = 3\n");
        int key = 3;
    
        char* text = cezar_decipher(cipher, key);

        printf("%s", text);
        printf("Added in plain_text.txt file");
        plain_text(text);

        free(text);
 
    }
    else
    {
        return EXIT_FAILURE;
    }

    }

    if(strcmp(choice, "N") == 0){
        
        char str2[MAXN];

        printf("Enter the word you want to encrypt: ");
        scanf("%s", str2);
        int key;
        printf("Enter the key you want to use: ");
        scanf("%d", &key);
        char* cipher = cezar_cipher(str2, key);
        printf("%s", cipher);

    }
        printf("Do you want to continue? (END/Yes)");
        scanf("%s", final);
        
    }
    return EXIT_SUCCESS;
    
}