/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:50:52 by smishos           #+#    #+#             */
/*   Updated: 2024/08/09 13:41:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
}	t_pipex;

void	execute_command(char **cmd, char *path_cmd, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	error_exit();
void	free_split(char **split);

#endif