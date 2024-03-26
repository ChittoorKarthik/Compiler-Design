#include <stdio.h>
#include <string.h>

void unput(char *input_buffer, int position, int length) {
    memmove(input_buffer + position, input_buffer + position + length, strlen(input_buffer) - position - length + 1);
}

int main() {
    char input_buffer[] = "+23456789";
    int position = 1; // Position of the first character of the substring to "unput"
    int length = 8;   // Length of the substring to "unput"
    
    // Before unput
    printf("Original string: %s\n", input_buffer);
    
    unput(input_buffer, position, length);
    
    // After unput
    printf("Modified string: %s\n", input_buffer);
    
    return 0;
}
