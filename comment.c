#include <stdio.h>
#include <string.h>

// Function to check if the line is a single-line comment
int isSingleLineComment(char line[]) {
    if (line[0] == '/' && line[1] == '/')
        return 1; // It's a single-line comment
    return 0;
}

// Function to check if the line is a multi-line comment
int isMultiLineComment(char line[]) {
    int len = strlen(line);
    if (line[0] == '/' && line[1] == '*' && line[len - 2] == '*' && line[len - 1] == '/')
        return 1; // It's a multi-line comment
    return 0;
}

int main() {
    char line[200];

    // Input a line
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    // Remove newline character from the input if present
    line[strcspn(line, "\n")] = 0;

    // Check for comments
    if (isSingleLineComment(line)) {
        printf("The given line is a single-line comment.\n");
    } else if (isMultiLineComment(line)) {
        printf("The given line is a multi-line comment.\n");
    } else {
        printf("The given line is NOT a comment.\n");
    }

    return 0;
}
