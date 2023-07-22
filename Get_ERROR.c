#include "main.h"

/**
 * get_error - calls the error according the builtin or syntax or permission
 * @data: data structure that contains arguments
 * @er_val: error value
 *
 * Return: error
 */
int get_error(data_shell *data, int er_val)
{
	char *error;

	switch (er_val)
	{
	case -1:
		error = error_env(data);
		break;
	case 126:
		error = error_path_126(data);
		break;
	case 127:
		error = error_not_found(data);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(data);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(data);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	data->status = er_val;
	return (er_val);
}

