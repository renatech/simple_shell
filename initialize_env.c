#include "main.h"

/**
 * init_env - initializes shell variables.
 * @env: struct of env vars.
 * @progname: name of prgram.
 * Return: struct with initialized shell vars.
 */
env_info *init_env(env_info *env, char *progname)
{

	env->in_shell = 1;
	env->status = 0;
	env->exit_sig = 0;
	env->env_var = NULL;
	env->pid = getpid();
	env->count = 1;
	env->progname = progname;


	signal(SIGINT, _signal_handled);

	return (env);
}

/**
 * init_program - initializes program.
 * @env: struct of env var.
 * @av: prgram arguments.
 * Return: nothing.
 */

void init_program(char *av, env_info *env)
{
	init_env(env, av);
	store_env(env);


}
