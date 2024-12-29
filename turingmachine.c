#include <stdio.h>
#include <string.h>

#define MAX 1000

// Tape and head position
char tape[MAX];
int head = 0;

// Function to move the tape head
void move(char direction) {
    if (direction == 'L') {
        head--;
    } else if (direction == 'R') {
        head++;
    }
}

// Function to check if a binary string has equal 0s and 1s
void turingMachine() {
    int done = 0;

    while (!done) {
        // If the current cell is '0', mark it as 'X'
        if (tape[head] == '0') {
            tape[head] = 'X';
            move('R');

            // Find the first '1' and mark it as 'Y'
            while (tape[head] != '1' && tape[head] != '\0') {
                move('R');
            }

            if (tape[head] == '1') {
                tape[head] = 'Y';
            } else {
                // No more 1s to pair with a 0
                done = 1;
                break;
            }
            move('L');
        }
        // If the current cell is '1', mark it as 'Y'
        else if (tape[head] == '1') {
            tape[head] = 'Y';
            move('R');

            // Find the first '0' and mark it as 'X'
            while (tape[head] != '0' && tape[head] != '\0') {
                move('R');
            }

            if (tape[head] == '0') {
                tape[head] = 'X';
            } else {
                // No more 0s to pair with a 1
                done = 1;
                break;
            }
            move('L');
        }
        // If tape has no more 0s or 1s
        else {
            done = 1;
        }
    }

    // Check if all symbols are marked
    for (int i = 0; i < strlen(tape); i++) {
        if (tape[i] == '0' || tape[i] == '1') {
            printf("The string does NOT have equal 0s and 1s.\n");
            return;
        }
    }
    printf("The string has equal 0s and 1s.\n");
}

int main() {
    printf("Enter a binary string (0s and 1s only): ");
    scanf("%s", tape);

    turingMachine();

    return 0;
}
