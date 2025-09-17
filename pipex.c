/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:43:07 by guisanto          #+#    #+#             */
/*   Updated: 2025/09/17 15:52:38 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

//serve para quando eu quiser duplicar um file descriptor, mas quero garantir que se der erro o programa pare.
static void safe_dup2(int oldfd, int newfd)
{
    if (dup2(oldfd, newfd) < 0)
    {
        perror("dup2 failed");
        exit(1);
    }
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Error opening input file");
		exit(1);
	}
	close(fd[0]);
	safe_dup2(fd[1], STDOUT_FILENO);
	safe_dup2(infile, STDIN_FILENO);
	close(infile);
	close(fd[1]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Error opening output file");
		exit(1);
	}
	close(fd[1]);
	safe_dup2(fd[0], STDIN_FILENO);
	safe_dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[0]);
	execute(argv[3], envp);
}
/*valgrind --leak-check=yes --track-origins=yes
 --track-fds=yes --trace-children=yes*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pid = 0;
	if (argc != 5)
    	return (ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2), 1);
	if (pipe(fd) == -1)
	{
		perror("Pipe creation failed");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, envp, fd);
	else
	{
		parent_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
