#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell *data_sh)
{
	int length;
	char *error;
	char *ver_str;
	char *message;

	ver_str = aux_itoa(data_sh->counter);
	message = ": Unable to add/remove from environment\n";
	length = _strlen(data_sh->av[0]) + _strlen(ver_str);
	length += _strlen(data_sh->args[0]) + _strlen(message) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, data_sh->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, message);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @data_sh: data relevant (counter, arguments).
 *
 * Return: The error str.
 */
char *error_path_126(data_shell *data_sh)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(data_sh->counter);
	length = _strlen(data_sh->av[0]) + _strlen(ver_str);
	length += _strlen(data_sh->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data_sh->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data_sh->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

