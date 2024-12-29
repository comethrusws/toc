#include <stdio.h>
#include <string.h>

// DFA for strings that start with "01"
int startsWith01(char str[]) {
    int state = 0; // Initial state
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (state) {
            case 0: if (ch == '0') state = 1; else return 0; break; // Dead if not '0'
            case 1: if (ch == '1') state = 2; else return 0; break; // Dead if not '1'
            case 2: break; // Stay in accepting state
        }
    }
    return (state == 2); // Check if final state is accepting
}

// DFA for strings that end with "01"
int endsWith01(char str[]) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (state) {
            case 0: state = (ch == '0') ? 1 : 0; break;
            case 1: state = (ch == '1') ? 2 : (ch == '0') ? 1 : 0; break;
            case 2: state = (ch == '0') ? 1 : 0; break;
        }
    }
    return (state == 2);
}

// DFA for strings that contain "001"
int contains001(char str[]) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (state) {
            case 0: state = (ch == '0') ? 1 : 0; break;
            case 1: state = (ch == '0') ? 2 : 0; break;
            case 2: state = (ch == '1') ? 3 : (ch == '0') ? 2 : 0; break;
            case 3: break; // Accepting state
        }
    }
    return (state == 3);
}

int main() {
    char str[100];

    // Input string
    printf("Enter a binary string: ");
    scanf("%s", str);

    // Check for each condition
    if (startsWith01(str))
        printf("The string starts with '01'.\n");
    else
        printf("The string does NOT start with '01'.\n");

    if (endsWith01(str))
        printf("The string ends with '01'.\n");
    else
        printf("The string does NOT end with '01'.\n");

    if (contains001(str))
        printf("The string contains '001' as a substring.\n");
    else
        printf("The string does NOT contain '001' as a substring.\n");

    return 0;
}
