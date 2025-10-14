#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int main() {
    char sentence[500];
    char words[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    int totalWords = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    // Convert to lowercase
    for (int i = 0; sentence[i]; i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Split sentence into words
    char *token = strtok(sentence, " ,.!?;\n");
    while (token != NULL) {
        int found = 0;

        // Check if word already exists
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        // If new word, add it
        if (!found) {
            strcpy(words[totalWords], token);
            count[totalWords] = 1;
            totalWords++;
        }

        token = strtok(NULL, " ,.!?;\n");
    }

    printf("\nWord Frequency:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s → %d\n", words[i], count[i]);
    }

    return 0;
}
