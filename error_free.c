/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:07:58 by guisanto          #+#    #+#             */
/*   Updated: 2025/03/11 16:17:35 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//apenas para erros e free
void	error(void)
{
	perror("Error");
	exit(1);
}
void    ft_free(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}