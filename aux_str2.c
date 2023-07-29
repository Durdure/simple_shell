#include "main.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s) {
    int length = strlen(s);
    char *dup = malloc(length + 1);
    
    if (dup != NULL) {
        strcpy(dup, s);
    }
    
    return dup;
}

/**
 * _strlen - calculate the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s) {
    int length = 0;
    
    while (*s != '\0') {
        length++;
        s++;
    }
    
    return length;
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim) {
    int matched = 0;
    
    while (*str != '\0') {
        if (strchr(delim, *str) != NULL) {
            matched++;
        }
        
        str++;
    }
    
    return matched;
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim) {
    static char *next = NULL;
    
    if (str != NULL) {
        next = str;
    }
    
    if (next == NULL) {
        return NULL;
    }
    
    char *token = next;
    char *delimiter = strpbrk(next, delim);
    
    if (delimiter != NULL) {
        *delimiter = '\0';
        next = delimiter + 1;
    } else {
        next = NULL;
    }
    
    return token;
}

/**
 * _isdigit - check if a string represents a digit
 *@s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s) {
    while (*s != '\0') {
        if (!isdigit(*s)) {
            return 0;
        }
        
        s++;
    }
    
    return 1;
}
