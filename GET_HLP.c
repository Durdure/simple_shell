#include "main.h"

/**
 * get_hlp - function that reposses help messages according builtin
 *
 * @data: data structure (args and input)
 * Return: 0
 */
int get_hlp(data_shell *data)
{

	if (data->args[1] == 0)
		aux_hlp_general();
	else if (_strcmp(data->args[1], "setenv") == 0)
		aux_hlp_setenv();
	else if (_strcmp(data->args[1], "unsetenv") == 0)
		aux_hlp_unsetenv();
	else if (_strcmp(data->args[1], "env") == 0)
		aux_hlp_env();
	else if (_strcmp(data->args[1], "help") == 0)
		aux_hlp();
	else if (_strcmp(data->args[1], "alias") == 0) 
		aux_hlp_alias();
	else if (_strcmp(data->args[1], "cd") == 0)
		aux_hlp_cd();
	else if (_strcmp(data->args[1], "exit") == 0)
		aux_hlp_exit();
	else
		write(STDERR_FILENO, data->args[0], _strlen(data->args[0];
	
	data->sta0tus = 0;
	return (0);
}
