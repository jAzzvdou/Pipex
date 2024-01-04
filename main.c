/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 17:28:39 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	start_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->path = NULL;
	pipex->cmdargs = NULL;
	pipex->envi = envp;
	pipex->fd[0] = open(argv[1], O_RDONLY);
	pipex->fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 00700);
	if (pipex->fd[0] < 0 || pipex->fd[1] < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	if (start_pipex(&pipex, argc, argv, envp) != 0)
		return (write(2, ".ERROR: start_pipex.\n", 20));
	cmd_controller(&pipex, argc, argv)
	return (0);
}
