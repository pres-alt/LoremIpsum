#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000




int read_cipher(char*filename, char*cipher)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        return EXIT_FAILURE;
    }
    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
void write_text(char*filename, char*text)
{
    FILE *fp = fopen(filename,"wb");
    fprintf(fp, "%s",text);
    fclose(fp);
}

char *vigenere_encrypt(char *plaintext, char *key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char *cipher = (char*)malloc(sizeof(char)*(text_length + 1));
    memset(cipher, '\0', sizeof(char) * (text_length + 1));

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher[text_length] = '\0';
    return cipher;
}
int main()
{
    printf("Enter filename for text. \n");
    char filename[MAXN];
    scanf("%s", filename);

    char text[MAXN];
    read_cipher(filename, text);

    printf("Enter filename for key. \n");
    scanf("%s", filename);

    char key[MAXN];
    read_cipher(filename, key);
    char *cipher = vigenere_encrypt(text, key);
    
    write_text("vigenere_result.txt", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}
