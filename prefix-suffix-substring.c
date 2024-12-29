#include <stdio.h>
#include <string.h>

// Function to print all prefixes of a string
void printPrefixes(char str[]) {
    int n = strlen(str);
    printf("\nPrefixes of the string are:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

// Function to print all suffixes of a string
void printSuffixes(char str[]) {
    int n = strlen(str);
    printf("\nSuffixes of the string are:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

// Function to print all substrings of a string
void printSubstrings(char str[]) {
    int n = strlen(str);
    printf("\nSubstrings of the string are:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Print prefixes, suffixes, and substrings
    printPrefixes(str);
    printSuffixes(str);
    printSubstrings(str);

    return 0;
}
