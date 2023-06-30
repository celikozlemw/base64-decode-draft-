#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // kullanılan karakter setini tanımlayın(hangi dil ise o karakterleri içermeli)
    const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    char *encoded_string = malloc(10000);
    scanf(" %s ", encoded_string);
    
    char *decoded_string = malloc(10000);
    int decoded_string_length = 0;
    //kod çözücü döngü
    for (int i = 0; i < strlen(encoded_string); i += 4) {
    
        char c1 = encoded_string[i];
        char c2 = encoded_string[i + 1];
        char c3 = encoded_string[i + 2];
        char c4 = encoded_string[i + 3];
    
        int b1 = base64_chars[c1] - 'A';
        int b2 = base64_chars[c2] - 'A';
        int b3 = base64_chars[c3] - 'A';
        int b4 = base64_chars[c4] - 'A';
        // dördüncü Base64 karakteri '=' ise kodu çözülmüş baytı 0 yap
        if (c4 == '=') {
            b4 = 0;
        }
        
        decoded_string[decoded_string_length++] = (b1 << 2) | (b2 >> 4);
        decoded_string[decoded_string_length++] = (b2 << 4) | (b3 >> 2);
        decoded_string[decoded_string_length++] = (b3 << 6) | b4;
    }
