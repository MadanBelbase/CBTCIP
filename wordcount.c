#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char paragraph[1000];
    int characters = 0, words = 0, lines = 1;

    // Prompt the user to enter the paragraph
    printf("Enter the paragraph (up to 1000 characters):\n");
    fgets(paragraph, 1000, stdin);

    // Count the characters, words, and lines
    for (int i = 0; paragraph[i]; i++) {
        characters++;

        if (paragraph[i] == '\n') {
            lines++;
        }

        if (isspace(paragraph[i])) {
            if (paragraph[i] == '\n') {
                lines++;
            } else {
                words++;
            }
        }
    }

    // Print the results
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}