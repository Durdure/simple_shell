#include "main.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval) {
    r_var *new_node = (r_var *)malloc(sizeof(r_var));
    new_node->lvar = lvar;
    new_node->var = (char *)malloc((strlen(var) + 1) * sizeof(char));
    strcpy(new_node->var, var);
    new_node->lval = lval;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        r_var *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head) {
    r_var *current = *head;
    r_var *next;

    while (current != NULL) {
        next = current->next;
        free(current->var);
        free(current);
        current = next;
    }

    *head = NULL;
}

