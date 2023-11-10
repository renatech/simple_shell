#include "main.h"

/**
 * get_enviroment - returns a copy of the environmental variable value
 * @name: string name of the environmental variable to retrieve
 * @env: linked list containing environmental variables
 * Return: copy of the value of the environmental variable
 */
char *get_enviroment(char *name, env_info *env)
{
	details *env_var = env->env_var;

	while (env_var)
	{
		if (_strcmp(name, env_var->envar) == 0)
		{
			if (env_var->value == NULL)
				return (NULL);
			return (string_duplicate(env_var->value));
		}
		env_var = env_var->next;
	}
	return (NULL);
}
