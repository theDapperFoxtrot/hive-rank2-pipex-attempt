/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:50:52 by smishos           #+#    #+#             */
/*   Updated: 2024/08/13 18:53:48 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> // for execve(), fork(), pipe(), dup2(), close()
# include <stdlib.h> // for malloc(), free()
# include <stdio.h> // for perror()
# include <string.h> // for strerror()
# include <fcntl.h> // for open()
# include <sys/wait.h> // for waitpid()
# include "./libft/libft.h" // for ft_split(), ft_strjoin()

typedef struct s_pipex
{
	int		infile; // Input file descriptor
	int		outfile; // Output file descriptor
	int		pipefd[2]; // Pipe file descriptors
	char	**cmd1; // Command 1
	char	**cmd2; // Command 2
	char	*path_cmd1; // Path to command 1
	char	*path_cmd2; // Path to command 2
}	t_pipex;

void	execute_command(char **cmd, char *path_cmd, char **envp); // Execute the command
char	*get_command_path(char *cmd, char **envp); // Get the path to the command
void	error_exit(); // Exit with an error
void	free_split(char **split); // Free the split

#endif