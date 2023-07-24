#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @data_sh: data structure (environ)
 *
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *data_sh)
{
	int i;
	char *var_env, *name_of_env;

	for (i = 0; data_sh->environ[i]; i++)
	{
		var_env = _strdup(data_sh->environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_of_env, name) == 0)
		{
			free(data_sh->environ[i]);
			data_sh->environ[i] = copy_info(name_of_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	data_sh->environ = _reallocdp(data_sh->environ, i, sizeof(char *) * (i + 2));
	data_sh->environ[i] = copy_info(name, value);
	data_sh->environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @data_sh: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *data_sh)
{

	if (data_sh->args[1] == NULL || data_sh->args[2] == NULL)
	{
		get_error(data_sh, -1);
		return (1);
	}

	set_env(data_sh->args[1], data_sh->args[2], data_sh);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @data_sh: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *data_sh)
{
	char **realloc_environ;
	char *var_env, *name_of_env;
	int i, j, k;

	if (data_sh->args[1] == NULL)
	{
		get_error(data_sh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; data_sh->_environ[i]; i++)
	{
		var_env = _strdup(data_sh->_environ[i]);
		name_of_env = _strtok(var_env, "=");
		if (_strcmp(name_env, data_sh->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(data_sh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; data_sh->environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = data_sh->environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(data_sh->environ[k]);
	free(data_sh->environ);
	data_sh->environ = realloc_environ;
	return (1);
}

