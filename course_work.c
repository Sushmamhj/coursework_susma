#include <stdio.h>
#include <string.h>

// Encryption function
void encrypt(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

// Decryption function
void decrypt(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline

    if (strlen(message) == 0) {
        printf("Message cannot be empty!\n");
        return 1;
    }

    printf("Enter a key (1-25): ");
    scanf("%d", &key);
    if (key < 1 || key > 25) {
        printf("Invalid key! Please enter a value between 1 and 25.\n");
        return 1;
    }

    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
