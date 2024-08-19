/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:50:58 by smishos           #+#    #+#             */
/*   Updated: 2024/08/13 18:53:41 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Execute the command
void	child_process(t_pipex *pipex, char **envp)
{
	close(pipex->pipefd[0]); // Close the read end of the pipe
	dup2(pipex->infile, STDIN_FILENO); // Redirect the input file to stdin
	dup2(pipex->pipefd[1], STDOUT_FILENO); // Redirect the write end of the pipe to stdout
	close(pipex->infile); // Close the input file
	close(pipex->pipefd[1]); // Close the write end of the pipe
	execute_command(pipex->cmd1, pipex->path_cmd1, envp); // Execute the command
}
// Execute the command
void	parent_process(t_pipex *pipex, char **envp)
{
	close(pipex->pipefd[1]); // Close the write end of the pipe
	dup2(pipex->pipefd[0], STDIN_FILENO); // Redirect the read end of the pipe to stdin
	dup2(pipex->outfile, STDOUT_FILENO); // Redirect the output file to stdout
	close(pipex->pipefd[0]); // Close the read end of the pipe
	close(pipex->outfile); // Close the output file
	execute_command(pipex->cmd2, pipex->path_cmd2, envp); // Execute the command
}
// Free the split
void	free_split(char **split)
{
	int	i;

	if (!split) // Check if the split is NULL
		return ; // If so, return
	i = 0; // Initialize the index
	while (split[i]) // Loop through the split
	{
		free(split[i]); // Free the split
		i++; // Increment the index
	}
	free(split); // Free the split
}
// Execute the command
void pipex_func(char **argv, char **envp, t_pipex pipex)
{
		pipex.infile = open(argv[1], O_RDONLY); // Open the file for reading
	if (pipex.infile == -1) // Check if the file was opened successfully
		error_exit(argv[1], 0); // If not, exit with an error
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open the file for writing
	if (pipex.outfile == -1) // Check if the file was opened successfully
		error_exit(argv[4], 1); // If not, exit with an error
	pipex.cmd1 = ft_split(argv[2], ' '); // Split the first command
	if (!pipex.cmd1) // Check if the split was successful
		error_exit("Failed to split cmd1", 1); // If not, exit with an error
	pipex.cmd2 = ft_split(argv[3], ' '); // Split the second command
	if (!pipex.cmd2) // Check if the split was successful
		error_exit("Failed to split cmd2", 1); // If not, exit with an error
	{
		free_split(pipex.cmd1); // Free the split
		error_exit("Failed to split cmd2", 1); // Exit with an error
	}
	pipex.path_cmd1 = get_command_path(pipex.cmd1[0], envp); // Get the path of the first command
	pipex.path_cmd2 = get_command_path(pipex.cmd2[0], envp); // Get the path of the second command
	if (pipe(pipex.pipefd) == -1) // Create a pipe
		error_exit(); // Exit with an error
	if (fork() == 0) // Fork the process
		child_process(&pipex, envp); // Execute the child process
	wait(NULL); // Wait for the child process to finish
	parent_process(&pipex, envp); // Execute the parent process
	close(pipex.infile); // Close the input file
	close(pipex.outfile); // Close the output file
	free_split(pipex.cmd1); // Free the split
	free_split(pipex.cmd2); // Free the split
	free(pipex.path_cmd1); // Free the path
	free(pipex.path_cmd2); // Free the path
}
 // Main function
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex; // Create a pipex struct

	if (argc != 5) // Check if the number of arguments is correct
	{
		ft_putstr_fd("Wrong number of arguments\n", 2); // Print an error message
		ft_putstr_fd("Expected format: ./pipex file1 cmd1 cmd2 file2\n", 2); // Print the expected format
		exit(0); // Exit with an error
	}
	else
		pipex_func(argv, envp, pipex); // Execute the pipex function
	return (0);
}
