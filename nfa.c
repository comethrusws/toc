#include <stdio.h>
#include <string.h>

// Function to check if the string starts with "01"
int starts_with_01(const char *str) {
    return (str[0] == '0' && str[1] == '1');
}

// Function to check if the string ends with "01"
int ends_with_01(const char *str) {
    int len = strlen(str);
    if (len < 2) return 0; // String too short to end with "01"
    return (str[len - 2] == '0' && str[len - 1] == '1');
}

// Function to check if the string contains the substring "01"
int contains_01(const char *str) {
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] == '0' && str[i + 1] == '1')
            return 1;
    }
    return 0;
}

int main() {
    char str[100];

    // Input string
    printf("Enter a binary string: ");
    scanf("%s", str);

    // Check each condition
    if (starts_with_01(str))
        printf("The string starts with '01'.\n");
    else
        printf("The string does not start with '01'.\n");

    if (ends_with_01(str))
        printf("The string ends with '01'.\n");
    else
        printf("The string does not end with '01'.\n");

    if (contains_01(str))
        printf("The string contains the substring '01'.\n");
    else
        printf("The string does not contain the substring '01'.\n");

    return 0;
}
