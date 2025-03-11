/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:43:07 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/11 13:02:30 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void babe_pipe(char **argv, char **envp, int *fd)
{
	int		file1;
	
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		perror("Error opening input file");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(argv[2], envp);
}	
void parent_process(char **argv, char **envp, int *fd)
{
	int file2;
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
	{	
		perror("Error opening output file");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid = 0;
	
	if (argc != 5)
		return (ft_putstr_fd("Error: Bad arguments\nEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2), 1);
	if (pipe(fd) == -1)
	{
		perror("Pipe creation failed");
		exit(1);
	}
	if ((pid = fork()) == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pid == 0)
		babe_pipe(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}		