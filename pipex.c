/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:49 by guisanto          #+#    #+#             */
/*   Updated: 2025/02/20 14:47:50 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>


int main() {
	int pipe_fd[2];  // Array para armazenar os descritores do pipe
	pid_t pid1, pid2;

	// Criando o pipe
	if (pipe(pipe_fd) == -1) {
		perror("pipe");
		exit(1);
	}

	// Primeiro processo
	pid1 = fork();
	if (pid1 == -1) {
		perror("fork");
		exit(1);
	}

	if (pid1 == 0) {  // Filho 1: Produzindo a saída
		close(pipe_fd[0]);  // Fechar a leitura do pipe
		dup2(pipe_fd[1], STDOUT_FILENO);  // Redireciona a saída padrão para o pipe
		close(pipe_fd[1]);  // Não precisamos mais do descritor do pipe

		execlp("ls", "ls", NULL);  // Executa o comando "ls"
		perror("execlp");  // Se execlp falhar
		exit(1);
	}

	// Segundo processo
	pid2 = fork();
	if (pid2 == -1) {
		perror("fork");
		exit(1);
	}

	if (pid2 == 0) {  // Filho 2: Consumindo a saída
		close(pipe_fd[1]);  // Fechar a escrita do pipe
		dup2(pipe_fd[0], STDIN_FILENO);  // Redireciona a entrada padrão para o pipe
		close(pipe_fd[0]);  // Não precisamos mais do descritor do pipe

		execlp("grep", "grep", "txt", NULL);  // Executa o comando "grep txt" com a saída de "ls"
		perror("execlp");  // Se execlp falhar
		exit(1);
	}

	// Processo pai: Espera os filhos
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);  // Espera o primeiro filho
	wait(NULL);  // Espera o segundo filho

	return 0;
}
