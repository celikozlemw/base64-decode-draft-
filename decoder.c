#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // Define the character set used for Base64 encoding.
    const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    // Get the Base64-encoded string from the user.
    char *encoded_string = malloc(10000);
    scanf(" %s ", encoded_string);
    // Initialize the decoded string.
    char *decoded_string = malloc(10000);
    int decoded_string_length = 0;
    // Decode the Base64-encoded string.
    for (int i = 0; i < strlen(encoded_string); i += 4) {
        // Get the four Base64 characters at the current position in the encoded string.
        char c1 = encoded_string[i];
        char c2 = encoded_string[i + 1];
        char c3 = encoded_string[i + 2];
        char c4 = encoded_string[i + 3];
        // Convert the four Base64 characters into three bytes.
        int b1 = base64_chars[c1] - 'A';
        int b2 = base64_chars[c2] - 'A';
        int b3 = base64_chars[c3] - 'A';
        int b4 = base64_chars[c4] - 'A';
        // If the fourth Base64 character is '=', then we need to pad the decoded byte with 0.
        if (c4 == '=') {
            b4 = 0;
        }
        // Append the three decoded bytes to the decoded string.
        decoded_string[decoded_string_length++] = (b1 << 2) | (b2 >> 4);
        decoded_string[decoded_string_length++] = (b2 << 4) | (b3 >> 2);
        decoded_string[decoded_string_length++] = (b3 << 6) | b4;
    }
