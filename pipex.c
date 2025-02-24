/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:43:07 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/24 19:11:35 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void babe_pipe(char **argv, char **envp, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Error");
		exit(1);
	}
	dup2(fd[2], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}	
void parent_process(char **argv, char **envp, int *fd)
{
	int outfile;
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid;
	
	if (argc != 5)
		return (ft_putstr_fd("Error: Bad arguments\nEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2), 1);
	if (pipe(fd) == -1 || (pid = fork()) == -1)
		error();
	if (pid == 0)
		babe_pipe(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}		