#include "main.h"

/**
 * Function to add a separate node at the end of the separator list
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the new node.
 */
sep_list *add_sep_node_end(sep_list **head, char sep) {
    sep_list *new_node = (sep_list *)malloc(sizeof(sep_list));
    new_node->sep = sep;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        sep_list *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

/**
 * free_sep_list - free the memory allocated for the separator list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head) {
    sep_list *current = *head;
    sep_list *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

/**
 * add_line_node_end - add a line node at the end of the line list
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line) {
    line_list *new_node = (line_list *)malloc(sizeof(line_list));
    new_node->line = line;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        line_list *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

/**
 * Function to free the memory allocated for the line list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head) {
    line_list *current = *head;
    line_list *next;

    while (current != NULL) {
        next = current->next;
        free(current->line);
        free(current);
        current = next;
    }

    *head = NULL;
}
