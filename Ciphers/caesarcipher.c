// Written by Carson Green. February 15, 2025

#include <stdio.h>

int main() {
    char input[256];
    int shift;
    printf("Caesar Cipher Program\n");
    printf("Enter 'd' to decode, or 'e' to encode: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'd' || input[0] == 'e') {
            break;
        } else {
            printf("Invalid input. Please enter 'd' to decode, or 'e' to encode: ");
        }
    }
    if (input[0] == 'd') {
        printf("Enter your ciphertext:\n");
        fgets(input, sizeof(input), stdin);
        printf("Enter the shift length:\n");
        scanf("%d", &shift);
        
        // Decode the ciphertext
        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] = (input[i] - 'a' - shift + 26) % 26 + 'a';
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] = (input[i] - 'A' - shift + 26) % 26 + 'A';
            }
        }
        printf("Decoded text: %s\n", input);
        
    } else {
        printf("Enter your plaintext:\n");
        fgets(input, sizeof(input), stdin);
        printf("Enter the shift length:\n");
        scanf("%d", &shift);
        
        // Encode the plaintext
        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                input[i] = (input[i] - 'a' + shift) % 26 + 'a';
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] = (input[i] - 'A' + shift) % 26 + 'A';
            }
        }
        printf("Encoded text: %s\n", input);
    }
    return 0;
}