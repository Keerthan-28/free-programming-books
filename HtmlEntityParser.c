#include <stdio.h>
#include <string.h>

char* entityParser(char* text) {
    static char result[1000]; // buffer to store the parsed result
    int i = 0; // index for input text
    int j = 0; // index for result

    while (text[i] != '\0') {
        if (strncmp(&text[i], "&quot;", 6) == 0) {
            result[j++] = '"';
            i += 6;
        } else if (strncmp(&text[i], "&apos;", 6) == 0) {
            result[j++] = '\'';
            i += 6;
        } else if (strncmp(&text[i], "&amp;", 5) == 0) {
            result[j++] = '&';
            i += 5;
        } else if (strncmp(&text[i], "&gt;", 4) == 0) {
            result[j++] = '>';
            i += 4;
        } else if (strncmp(&text[i], "&lt;", 4) == 0) {
            result[j++] = '<';
            i += 4;
        } else if (strncmp(&text[i], "&frasl;", 7) == 0) {
            result[j++] = '/';
            i += 7;
        } else {
            result[j++] = text[i++];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char text1[] = "&amp; is an HTML entity but &ambassador; is not.";
    char text2[] = "and I quote: &quot;...&quot;";
    
    printf("%s\n", entityParser(text1));
    printf("%s\n", entityParser(text2));
    
    return 0;
}
