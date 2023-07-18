#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
//#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Explanation: linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @data_type_f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*data_type_f)(data_shell *datash);
} builtin_t;

/**
 * struct r_var_list - single linked list
 * @len_var: variable length
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Explanation: single linked list which store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct data - struct which contains all relevant data on runtime
 * @args: tokens of the command(cmd) line
 * @stat: last status of the shell
 * @count: lines counter
 * @_environ: variable of the environment
 * @av: argument vector
 * @input: command line written by the user
 * @pro_id: process ID of the shell
 */
typedef struct data
{
	char **args;
	int stat;
	int count;
	char **_environ;
	char **av;
	char *input;
	char *pro_id;
} data_shell;

/**
 * struct line_list_s - single linked list
 * @line: command(cmd) line
 * @next: next node
 * Explanation: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

// For AUXILIARY_list.c
void free_sep_list(sep_list **head);
void free_line_list(line_list **head);
sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);

/* For READ_line.c */
char *read_line(int *i_eof);

#endif // MAIN_H
