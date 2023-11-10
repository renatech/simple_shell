#include "main.h"


/**
 * main - main file for shell.
 * @ac: number of arguments.
 * @av: argument strings.
 * Return: 0 on success.
 */
int main(int ac __attribute__((unused)), char *av[])
{
	env_info env;
	bool interactive;
	char *line = NULL, **args, *afterhash;
	ssize_t chars_read = 0, inter;
	size_t len;
	pid_t pid;
	int fail_check = 0;

	init_program(av[0], &env);
	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		if (interactive)
			inter = interactive_mode(&env);
		if (inter == -1)
			return (1);
		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
			handle_eof(interactive, line, &env);
		if (is_all_delims(line, " \n"))
			continue;
		afterhash = tokenize_hash(line);
		if (!afterhash)
		{	free_chars(line, &env);
			exit(EXIT_SUCCESS);
		}
		args = tokenize(afterhash, &env);
		fail_check = find_builtin(args, &env, line);
		if (fail_check == -1)
		{
			pid = fork();
			if (pid == 0)
				processing(&env, args);
			else
				env.status = wait_exit(&env);
		}
		free(args);
	}
	exit(env.status);
}
