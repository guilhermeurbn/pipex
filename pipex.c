/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:49 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/03 16:43:00 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(void)
{
    int pipefd[2];
    pid_t pid1, pid2;

    //criando o pipe
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    //primeiro Fork (processo 1)
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid1 == 0) //processo 1
    {
        //redirecionar saida para o pipe
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        char *cmd1[] = {"cat", "file.txt", NULL};
        execvp(cmd1[0], cmd1);
        perror("execvp");
        exit(1);
    }
    pid2 = fork();
    if (pid1 == -1)
    {
        perror("fork2");
        exit(1);
    }
    if (pid2 == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        
        //executar o grep
        char *cmd2[] = {"grep", "something", NULL};
        execvp(cmd2[0], cmd2);
        perror("execvp2");
        exit(1);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    
    //esperando os filhos terminarem
    wait(NULL);
    wait(NULL);
    return (0);
}
