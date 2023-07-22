#include "main.h"

/**
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locates a command
 * @command: command name
 * @_environment: environment variable
 *
 * Return: location of the command.
 */
char *_which(char *command, char **_environment)
{
	char *path, *ptr_path, *token_path, *direction;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environment);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(command);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(command, &st) == 0)
					return (command);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(direction, token_path);
			_strcat(direction, "/");
			_strcat(direction, command);
			_strcat(direction, "\0");
			if (stat(direction, &st) == 0)
			{
				free(ptr_path);
				return (direction);
			}
			free(direction);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(command, &st) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (command);
	return (NULL);
}

/**
 * is_executable - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int i;
	char *input;

	input = datash->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permissions to access
 *
 * @dis: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dis, data_shell *datash)
{
	if (dis == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dis) != 0)
	{
		if (access(dis, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dis);
			return (1);
		}
		free(dis);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_execut - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int execut;
	char *direction;
	(void) wpd;

	execut = is_executable(datash);
	if (execut == -1)
		return (1);
	if (execut == 0)
	{
		direction = _which(datash->args[0], datash->_environment);
		if (check_error_cmd(direction, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (execut == 0)
			direction = _which(datash->args[0], datash->_environment);
		else
			direction = datash->args[0];
		execve(direction + execute, datash->args, datash->_environment);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}

