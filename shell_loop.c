#include "main.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in) {
    char *out = malloc(strlen(in) + 1); // Allocate memory for the output string

    int i = 0, j = 0;
    int isInComment = 0;

    while (in[i] != '\0') {
        if (!isInComment && in[i] == '#') {
            isInComment = 1;
            i++;
        }

        if (!isInComment) {
            out[j] = in[i];
            j++;
	}

        if (isInComment && in[i] == '\n') {
            isInComment = 0;
        }

        i++;
    }

    out[j] = '\0';
    return out;
}

 /**
 * shell_loop - the main shell loop
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash) {
    char input[100];

    while (1) {
        printf("Shell> ");
        fgets(input, sizeof(input), stdin);

        char *clean_input = without_comment(input);

        // Placeholder code for processing the cleaned input

        free(clean_input);
    }
}
