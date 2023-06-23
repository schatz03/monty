#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim(char *str) {
    // Remove leading spaces
    char *start = str;
    while (isspace(*start))
        start++;

    // Remove trailing spaces
    char *end = str + strlen(str) - 1;
    while (end > start && isspace(*end))
        end--;

    // Null-terminate the trimmed string
    *(end + 1) = '\0';

    // Move the trimmed string to the beginning of the original string
    memmove(str, start, strlen(start) + 1);
}

void processLine(char *line) {
    // Remove trailing newline character
    line[strcspn(line, "\n")] = '\0';

    // Skip empty lines
    if (strlen(line) == 0)
        return;

    // Check and remove spaces before the first word
    char *firstWord = line;
    while (isspace(*firstWord))
        firstWord++;

    // Extract the opcode
    char *opcode = strtok(firstWord, " ");

    if (opcode != NULL) {
        trim(opcode);
        printf("Opcode: %s\n", opcode);

        // Extract the argument (if any)
        char *arguments = strtok(NULL, " ");
        if (arguments != NULL) {
            trim(arguments);
            printf("Argument: %s\n", arguments);
        }
    }
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        processLine(line);
    }

    fclose(file);
}

int main() {
    const char *filename = "001.m";
    processFile(filename);
    return 0;
}
