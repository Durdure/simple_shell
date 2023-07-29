#include "main.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j) {
    if (*n < j + 1) {
        *n = j + 1;
        *lineptr = realloc(*lineptr, *n);
    }
    strncpy(*lineptr, buffer, j);
    (*lineptr)[j] = '\0';
}

}
/**
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream) {
    char buffer[256];
    ssize_t i, j;
    size_t len = 0;
    
    while (fgets(buffer, sizeof(buffer), stream) != NULL) {
        len = strlen(buffer);
        i = 0;
        
        while (i < len && (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')) {
            i++;
        }
	if (i == len) {
            continue;  // Skip empty lines
        }

        j = len - 1;

        while (j >= i && (buffer[j] == ' ' || buffer[j] == '\t' || buffer[j] == '\n')) {
            j--;
        }

        bring_line(lineptr, n, buffer + i, j - i + 1);
        return j - i + 1;
    }

    return -1;  // Return -1 to indicate end of file or error
}

