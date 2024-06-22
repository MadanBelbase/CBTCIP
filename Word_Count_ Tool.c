#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    int word_count = 0, line_count = 0, char_count = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        int i = 0;
        line_count++;

        // Count characters in the current line
        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
                char_count++;
                // Skip to the end of the word
                while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0') {
                    i++;
                }
                word_count++;
            } else {
                i++;
            }
        }
    }
    fclose(fp);
    printf("Number of words in %s: %d\n", filename, word_count);
    printf("Number of lines in %s: %d\n", filename, line_count);
    printf("Number of characters in %s: %d\n", filename, char_count);

    return 0;
}