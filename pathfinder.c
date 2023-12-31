/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:32:17 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 18:23:00 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(t_pipex *pipex)
{
	int		i;
	int		ii;
	char	**paths;
	char	*path;
	char	*aux;

	if (ft_strchr(pipex->cmdargs[0], '/'))
		return (pipex->cmdargs[0]);
	ii = 0;
	while (ft_strncmp(pipex->envi[ii], "PATH=", 5))
		ii++;
	paths = ft_split(pipex->envi[ii] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		aux = ft_strjoin(paths[i], "/");
		path = ft_strjoin(aux, pipex->cmdargs[0]);
		free(aux);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	cleaner_matrix(paths);
	return (NULL);
}
