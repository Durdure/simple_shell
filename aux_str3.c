#include "main.h"

/**
 * rev_string - reverse a string
 * @s: String
 * Return: no return
 */ 
void rev_string(char *s) {
    int length = strlen(s);
    
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}
