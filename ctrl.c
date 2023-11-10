#include "main.h"

/**
 * _signal_handled - voids a signal and prints prompt.
 * @signal: signal to be ignored.
 * Return: nothing.
 */

void _signal_handled(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);

}
