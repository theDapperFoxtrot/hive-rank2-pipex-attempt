/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:50:58 by smishos           #+#    #+#             */
/*   Updated: 2024/07/16 17:49:06 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex, char **envp)
{
	close(pipex->pipefd[0]);
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->infile);
	close(pipex->pipefd[1]);
	execute_command(pipex->cmd1, pipex->path_cmd1, envp);
}

void	parent_process(t_pipex *pipex, char **envp)
{
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->pipefd[0]);
	close(pipex->outfile);
	execute_command(pipex->cmd2, pipex->path_cmd2, envp);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_exit("Invalid number of arguments");
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.infile < 0 || pipex.outfile < 0)
		error_exit("");
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.path_cmd1 = get_command_path(pipex.cmd1[0], envp);
	pipex.path_cmd2 = get_command_path(pipex.cmd2[0], envp);
	if (pipe(pipex.pipefd) == -1)
		error_exit("");
	if (fork() == 0)
		child_process(&pipex, envp);
	wait(NULL);
	parent_process(&pipex, envp);
	close(pipex.infile);
	close(pipex.outfile);
	ft_free_split(pipex.cmd1);
	ft_free_split(pipex.cmd2);
	free(pipex.path_cmd1);
	free(pipex.path_cmd2);
	return (0);
}
