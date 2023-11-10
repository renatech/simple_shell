#include "main.h"

/**
 * error_messages - prints error message to STDERR_FILENO.
 * @env: struct fo shell variables.
 * @command: command passed.
 * Return: nothing.
 */
int error_messages(env_info *env, char *command)
{
	char buffer[1024];

	itoa(env->count, buffer, env);

	write(STDERR_FILENO, env->progname, string_length(env->progname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, string_length(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, string_length(command));
	write(STDERR_FILENO, ": not found\n", string_length(": not found\n"));
	return (0);
}

/**
 * error_messages - prints error message to STDERR_FILENO.
 * @env: struct fo shell variables.
 * @command: command passed.
 * Return: nothing.
 */


int print_error_messages(env_info *env, char **command)
{
	char buffer[1024];
	int length = string_length(": Illegal number: ");

	itoa(env->count, buffer, env);

	write(STDERR_FILENO, env->progname, string_length(env->progname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, string_length(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[0], string_length(command[0]));
	write(STDERR_FILENO, ": Illegal number: ", length);
	write(STDERR_FILENO, command[1], string_length(command[1]));
	_putchar('\n');
	return (0);
}
