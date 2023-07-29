#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof) {
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    
    nread = getline(&line, &bufsize, stdin);
    
    if (nread == -1) {
        *i_eof = 1;  // Set the EOF indicator if getline fails
    } else {
        *i_eof = 0;  // Reset the EOF indicator
        line[nread-1] = '\0';  // Remove the newline character at the end
    }
    
    return line;
}
