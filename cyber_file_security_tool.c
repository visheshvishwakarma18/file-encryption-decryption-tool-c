#include <stdio.h>
#include <stdlib.h>

void encryptFile(char *inputFile, char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch + key, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("File encrypted successfully!\n");
}

void decryptFile(char *inputFile, char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch - key, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("File decrypted successfully!\n");
}

int main() {
    int choice, key;

    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter key value: ");
    scanf("%d", &key);

    if (choice == 1) {
        encryptFile("input.txt", "encrypted.txt", key);
    } else if (choice == 2) {
        decryptFile("encrypted.txt", "decrypted.txt", key);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}