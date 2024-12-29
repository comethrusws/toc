#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
};
int numKeywords = 32;

// Function to check if the input is a keyword
int isKeyword(char str[]) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1; // It is a keyword
    }
    return 0; // Not a keyword
}

// Function to check if the input is a valid identifier
int isValidIdentifier(char str[]) {
    // Check if the first character is a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;

    // Check remaining characters for validity
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0; // Invalid character found
    }

    return 1; // Valid identifier
}

int main() {
    char input[100];

    // Input a string
    printf("Enter the input string: ");
    scanf("%s", input);

    // Check if the input is a keyword
    if (isKeyword(input)) {
        printf("'%s' is a keyword.\n", input);
    }
    // Check if it is a valid identifier
    else if (isValidIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is NOT a valid identifier.\n", input);
    }

    return 0;
}
