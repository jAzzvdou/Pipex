/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:44 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/20 16:42:03 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleaner_child(t_info *info)
{
	int	i;

	i = -1;
	while(info->cmds[++i])
		free(info->cmds[i]);
	free(info->cmds);
	free(info->cmd);
}

char	*catch_cmd(char **path, char *cmd)
{
	char	*temp;
	char	*com;

	while (*path)
	{

void	p1_child(t_info info, char **argv, char **envp)
{
	dup2(info.pipes[1], 1);
	close(info.pipes[0]);
	dup2(info.infile, 0);
	info.cmds = ft_split(argv[2], ' ');
	info.cmd = catch_cmd(info.cmd_path, info.cmds[0]);
	if (!info.cmd)
	{
		write(2, "ERROR: Command not found.", 25);
		cleaner_child(&info);
		exit(1);
	}
	execve(info.cmd, info.cmds, envp);
}

void	p2_child(t_info info, char **argv, char **envp)
{
	dup2(info.pipes[0], 0);
	close(info.pipes[1]);
	dup2(info.infile, 1);
	info.cmds = ft_split(argv[3], ' ');
	info.cmd = catch_cmd(info.cmd_path, info.cmds[0]);
	if (!info.cmd)
	{
		write(2, "ERROR: Command not found.", 25);
		cleaner_child(&info);
		exit(1);
	}
	execve(info.cmd, info.cmds, envp);
}