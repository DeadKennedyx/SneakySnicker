#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

void handleErrors(void) {
    fprintf(stderr, "Error occurred.\n");
    exit(EXIT_FAILURE);
}

void encryptFile(const char *inputFileName, const char *outputFileName, const unsigned char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // this just to get the file length and rewind is for putting the file read to the beggining again
    fseek(inputFile, 0, SEEK_END);
    size_t fileLen = ftell(inputFile);
    rewind(inputFile);

    AES_KEY aesKey;
    if (AES_set_encrypt_key(key, 128, &aesKey) < 0) {
        handleErrors();
    }

    unsigned char inData[BLOCK_SIZE], outData[BLOCK_SIZE];
    size_t bytesRead = 0;

    while (bytesRead < fileLen) {
        size_t toRead = fread(inData, 1, BLOCK_SIZE, inputFile);
        bytesRead += toRead;

        if (toRead < BLOCK_SIZE) {
            // since AES blocks are 16 bytes if the last to read block is less than 16 bytes then we would fill it with zeroes
            memset(inData + toRead, 0, BLOCK_SIZE - toRead);    
        }

        AES_encrypt(inData, outData, &aesKey);
        fwrite(outData, 1, BLOCK_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName, const unsigned char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    size_t fileLen = ftell(inputFile);
    rewind(inputFile);

    AES_KEY aesKey;
    if (AES_set_decrypt_key(key, 128, &aesKey) < 0) {
        handleErrors();
    }

    unsigned char inData[BLOCK_SIZE], outData[BLOCK_SIZE];
    size_t bytesRead = 0;

    while (bytesRead < fileLen) {
        size_t toRead = fread(inData, 1, BLOCK_SIZE, inputFile);
        bytesRead += toRead;

        AES_decrypt(inData, outData, &aesKey);

        if (bytesRead == fileLen) {
            size_t padding = outData[BLOCK_SIZE - 1];
            fwrite(outData, 1, BLOCK_SIZE - padding, outputFile);
        } else {
            fwrite(outData, 1, BLOCK_SIZE, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFileName[256];
    char outputFileName[256];
    unsigned char key[AES_BLOCK_SIZE] = "0123456789abcdef";  // 128-bit key
    char choice;

    printf("Enter 'e' for encryption or 'd' for decryption: ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        printf("Enter the input file name (with extension): ");
        scanf("%255s", inputFileName);

        snprintf(outputFileName, sizeof(outputFileName), "%s_encrypted", inputFileName);

        encryptFile(inputFileName, outputFileName, key);

        printf("Encryption completed. Encrypted file: %s\n", outputFileName);
    } else if (choice == 'd' || choice == 'D') {
        printf("Enter the input file name (with extension): ");
        scanf("%255s", inputFileName);

        // Assume the output file will have the same name with "_decrypted" appended
        // This part sucks because it appends to the encrypted name already so it looks messy but im too lazy to fix it
        snprintf(outputFileName, sizeof(outputFileName), "%s_decrypted", inputFileName);

        decryptFile(inputFileName, outputFileName, key);

        printf("Decryption completed. Decrypted file: %s\n", outputFileName);
    } else {
        printf("Invalid choice. Exiting.\n");
    }

    return 0;
}