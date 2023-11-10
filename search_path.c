#include "main.h"

/**
 * search_directory - searches for an executable in the PATH directories
 * @command: name of the executable to find
 * @env: linked list of env variables which contains PATH
 * Return: full path to the executable
 */
char *search_directory(char *command, env_info *env)
{
	char *dir, *value = get_enviroment("PATH", env);
	char *command_path = NULL;
	int i, j;
	struct stat st;

	if (value == NULL)
		return (NULL);
	dir = strtok(value, ":\n");
	while (dir != NULL)
	{
		command_path = malloc(string_length(dir) + string_length(command) + 2);
		if (command_path == NULL)
			exit(1);
		for (i = 0; dir[i]; i++)
			command_path[i] = dir[i];
		command_path[i] = '/';
		i++;
		for (j = 0; command[j]; j++)
			command_path[i + j] = command[j];
		command_path[i + j] = '\0';
		if (stat(command_path, &st) == 0)
		{
			free(value);
			return (command_path);
		}
		free(command_path);
		dir = strtok(NULL, ":\n");
	}
	free(value);
	return (NULL);
}
