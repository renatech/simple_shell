#include "main.h"


/**
 * pathfinder - finds the command path and exeutes.
 * @args: command.
 * @env: struct of shell var.
 * Return: nothing.
 */

int pathfinder(char **args, env_info *env)
{
	char *command_path = NULL;
	int fail_check2;

	if (!(args[0][0] == '.' && args[0][1] == '/'))
		command_path = search_directory(args[0], env);

	if (command_path != NULL)
		fail_check2 = execve(string_duplicate(command_path), args, NULL);
	else
		fail_check2 = execve(string_duplicate(args[0]), args, NULL);

	if (command_path)
	{
		free(command_path);
		command_path = NULL;
	}
	return (fail_check2);
}
