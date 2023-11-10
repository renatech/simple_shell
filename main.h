#ifndef MAIN_H
#define MAIN_H


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
extern char **environ;


/**
 * struct details - singly linked list.
 * @envar: env var to be evaluated.
 * @value: value of env var.
 * @next:next node in the list.
 *
 * Description: singly linked list that establishes env var.
 */

typedef struct details
{
	char  *envar;
	char *value;
	struct details *next;


} details;
/**
 * struct hist_t - singly linked list
 * @cmd: string - (malloc string)
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */


typedef struct hist_t
{

	char *cmd;
	struct hist_t *next;
} hist_t;


/**
 * struct env_info - structure of specific shell environment variables.
 * @exit_sig: holds the exit signal.
 * @in_shell: in shell or not.
 * @status: status of last command.
 * @env_var: linked list of env var.
 * @pid: process id.
 * @count: number of errors.
 * @progname: program name.
 * @history: linked list of commands entered.
 *Description: shell variable.s
 */

typedef struct env_info
{
	int in_shell;
	int status;
	int exit_sig;
	struct details *env_var;
	pid_t pid;
	hist_t history;
	int count;
	char *progname;
} env_info;


/**
 * struct b_t - struct for built in functions.
 * @cmd: command.
 * @func: function associated with command.
 *
 * Description: Builtin function command and corresponding function.
 */

typedef struct b_t
{
	char *cmd;
	int (*func)(char **, env_info *);
} b_t;


/**
 * struct help_list - struct for help files of specific commands.
 * @cmd: command.
 * @helpfile: help file for command.
 *
 * Description: commands and their corresponding help files.
 */

typedef struct help_list
{
	char *cmd;
	char *helpfile;
} help_list;

char *string_duplicate(char *string);
int string_length(char *s);
bool is_interactive(void);
char *get_enviroment(char *name, env_info *env);
char *search_directory(char *command, env_info *env);
int _putchar(char c);
int print_enviroment(char **environ, env_info *env);
void exit_check(char **cmd, env_info *env);
int shell_exit(char **cmd, env_info *env, char *line);
int find_builtin(char **cmd, env_info *env, char *line);
int words_to_count(char *s, char *d);
char *each_word(char *s);
char **_strtok(char *str, char *d);
int _strcmp(char *s1, char *s2);
env_info *init_env(env_info *env, char *progname);
int exit_status(char **cmd, env_info *env);
char *reverse(char *s, env_info *env);
char *itoa(int num, char *s, env_info *env);
int echo_parser(char **cmd, env_info *env);
int echo_pid(char **cmd, env_info *env);
int echo_exit_status(char **cmd, env_info *env);
void addnode(details **head, char *var, char *value);
int set_env(char **cmd, env_info *env);
void reverse_list(details **head);
int print_list(env_info **env);
int unset_env(char **cmd, env_info *env);
unsigned int sortlist(details **list, char *cmd, env_info *env);
int deletenode(details **head, char *var, env_info *env);
char **tokenize_env(char *line, env_info *env);
char *tokenize_hash(char *line);
void store_env(env_info *env);
char **tokenize(char *line, env_info *env);
void free_listint2(details **head);
char *string_duplicate(char *str);
int error_messages(env_info *env, char *command);
void rearrange(details **head, details *node);
int free_chars(char *line, env_info *env);
int interactive_mode(env_info *env);
int pathfinder(char **args, env_info *env);
void init_program(char *av, env_info *env);
int wait_exit(env_info *env);
void processing(env_info *env, char **args);
bool is_all_delims(char *line, char *delims);
void _signal_handled(int signal);
void handle_eof(bool interactive, char *line, env_info *env);
int print_error_messages(env_info *env, char **command);
#endif
