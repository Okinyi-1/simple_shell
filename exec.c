#include "main.h"
/**
 * execute_command - performs requested command
 *
 * @command: pointer to the command entered
 * @args: pointer to arguments eneterd
 * @env: pointer to the simple shell environment
 */
void execute_command(char *command, char **args, char **env)
{
	char *cmd_path;
	pid_t pid;
	int status;
	/* Check if the command is a built-in command */
	if (strcmp(command, "printenv") == 0)
	{
		print_environment();
		return;
	} /* Check if the command is a full path to an executable*/
	if (access(command, X_OK) == 0)
	{
		cmd_path = strdup(command);
	}
	else
	{ /* If not, try to find the command in the directories listed in the PATH */
		cmd_path = path_lookup(command);
		if (cmd_path == NULL)
		{
			printf("Command not found: %s\n", command);
			return;
		}
	} /* Fork a new process to execute the command */
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(cmd_path, args, env);
		perror("Command execution error");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		printf("Command returned with an error (exit status: %d)\n", exit_status);
	}
	free(cmd_path);
}
