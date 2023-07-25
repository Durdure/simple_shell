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

/* AUXILIARY_list.c */
void free_sep_list(sep_list **head);
void free_line_list(line_list **head);
sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);

/* READ_line.c */
char *read_line(int *i_eof);

/* SHELL_loop.c */
void shell_loop(data_shell *data_sh);
char *without_comment(char in);

/* get_L.c */
ssize_t get_line(char **line_ptr, size_t *n, FILE *stream);
void bring_line(char **line_ptr, size_t *n, char *buffer, size_t j);

/* command_exect.c */
int is_executable(data_shell *data_sh);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int check_error_cmd(char *dir, data_shell *data_sh);
int cmd_exec(data_shell *data_sh);

/* command.c */
void cd_to(data_shell *data_sh);
void cd_previous(data_shell *data_sh);
void cd_to_home(data_shell *data_sh);
void cd_dot(data_shell *data_sh);

/* COMMAND_shell.c */
int cd_shell(data_shell *data_sh);

/*  AUXILIARY_LIST_1.c */
void free_rvar_list(r_var **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);

/* Get_ERROR.c */
int get_error(data_shell *data_shell, int eval);

/* AUX_H_1.C */
void aux_hlp_exit(void);
void aux_hlp_unsetenv(void);
void aux_hlp_general(void);
void aux_hlp_setenv(void);
void aux_hlp_env(void);

/* AUX_HE_2.c */
void aux_hlp_alias(void);
void aux_hlp_cd(void);
void aux_hlp_env(void);

/* GET_H.c */
int get_hlp(data_shell *data_sh);

/* AUX_ERROR.c */
char *error_get_cd(data_shell *data_sh);
char *error_not_found(data_shell *data_sh);
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_exit_shell(data_shell *data_sh);

/*  AUX_ERROR_2.c */
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_env(data_shell *datash);
char *error_get_alias(char **args);
char *error_path_126(data_shell *datash);

/* environ_1.c */
int _env(data_shell *data_sh);
char *get_env(const char *name, char **environ);

/* environ_2.c */
void set_env(char *name, char *value, data_shell *data_sh);
int _setenv(data_shell *data_sh);
char *copy_info(char *name, char *value);
int _unsetenv(data_shell *data_sh);

/* ex_line.c */
int ex_line(data_shell *data_sh);

/* command_sh.c */
int command_sh(data_shell *data_sh);

/* AUXILIARY_STRING.c */
int _str_cmp(char *s1, char *s2);
char *_str_chr(char *s, char c);
char *_str_cat(char *dest, const char *sourc);
char *_str_cpy(char *dest, char *sourc);
int _str_spn(char *s, char *accpt);

/* AUXILIARY_STRING_1.c */
int cmp_chars(char str[], const char *dl_meter);
int _isdigit(const char *s);
char *_strtok(char str[], const char *dl_meter);
int _strlen(const char *s);
char *_strdup(const char *s);

/* SPLIT.C */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* AUXILIARY_stdlib.c */
int _atoi(char *s);
char *aux_itoa(int m);
int get_len(int n);

/* syntax_error_checking.c */
int error_sep_op(char *input, int i, char last);
int check_syntax_error(data_shell *datash, char *input);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int first_char(char *input, int *i);
int repeated_char(char *input, int i);


/* AUX_memory.c*/


#endif
