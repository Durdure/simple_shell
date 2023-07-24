#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @n_env: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *n_env, const char *name)
{
	int i;

	for (i = 0; n_env[i] != '='; i++)
	{
		if (n_env[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * get_env - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *get_env(const char *name, char **environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *data_sh)
{
	int i, j;

	for (i = 0; data_sh->environ[i]; i++)
	{

		for (j = 0; data_sh->environ[i][j]; j++)
			;

		write(STDOUT_FILENO, data_sh->environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_sh->status = 0;

	return (1);
}

