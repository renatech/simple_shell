#include "main.h"

/**
 * set_env - sets an env variable.
 * @cmd: command.
 * @env: struc of env variables.
 * Return: nothing.
 */


int set_env(char **cmd, env_info *env)
{
	details *nodescanner = env->env_var;
	char *var, *value, *node;

	var = cmd[1];
	value = cmd[2];

	if (!value && var)
	{
		env->status = 2;
                error_messages(env, cmd[0]);
                env->count++;
		return (env->status);
	}


	else if (var && value && !cmd[3])
	{
		if (!nodescanner)
		{
			addnode(&env->env_var, var, value);
			return (0);
		}

		while (nodescanner)
		{
			node = (nodescanner->envar);

			if (!_strcmp(var, node))
			{
				(nodescanner->value) = value;
				return (0);
			}
			nodescanner = (nodescanner->next);
		}
		if (!nodescanner && _strcmp(var, node))
			addnode(&(env->env_var), var, value);
	}
	else
	{
		env->status = 0;
		error_messages(env, cmd[0]);
		env->count++;
	}
	return (env->status);
}

/**
 * addnode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @value:  value of variable.
 * Return: nothing.
 */

void addnode(details **head, char *var, char *value)
{
	details  *node;

	node = malloc(sizeof(details));
	if (node)
	{
		node->envar = NULL;
		node->value = NULL;
		node->next = NULL;
		if (var && value)
		{
			node->envar = string_duplicate(var);
			if (!node->envar)
			{
				free(node);
				return;
			}
			node->value = string_duplicate(value);
			if (!node->envar)
			{
				free(node->envar);
				free(node);
				return;
			}
		}
	}

	rearrange(head, node);
}

/**
 * rearrange - adds node to end of list.
 * @head: double pointer to linked list.
 * @node: node in linked list.
 * Return: nothing.
 */

void rearrange(details **head, details *node)
{
	details *end;


	if (*head)
	{
		end = *head;
		while (end->next)
			end = end->next;
		end->next = node;
		node->next = NULL;
	}
	else
	{
		*head = node;
		node->next = NULL;
	}
}

/**
 * reverse_list - reverses linked list.
 * @head: pointer to end of list.
 * Return: Nothing.
 */
void reverse_list(details **head)
{
	details *next, *prevnode = NULL;

	while (*head)
	{


		next = (*head)->next;

		(*head)->next = prevnode;

		prevnode = *head;

		*head = next;

	}

	*head = prevnode;
}
