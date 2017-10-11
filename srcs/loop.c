/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:08:07 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 15:15:32 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_prompt(void)
{
	char	*prompt;
	char	**secu;

	secu = (char **)ft_memalloc(sizeof(char *) * 3);
	secu[0] = ft_strdup("cd");
	secu[1] = ft_strdup("/");
	secu[2] = NULL;
	prompt = ft_strnew(4096);
	prompt = (getcwd(prompt, 4096)) ? (getcwd(prompt, 4096)) : NULL;
	if (!prompt)
		ft_cd(secu);
	prompt = (getcwd(prompt, 4096)) ? (getcwd(prompt, 4096)) : NULL;
	prompt = ft_strjoini(prompt, " -> ", 1);
	ft_putstr(prompt);
	free(prompt);
	ft_array_free(secu);
}

void		m_loop(void)
{
	char	*line;
	char	**cmd;
	char	**exec;
	int		status;
	int		i;

	status = 0;
	while (status >= 0)
	{
		ft_prompt();
		get_next_line(0, &line);
		if (line)
		{
			exec = ft_strsplit(line, ';');
			i = 0;
			while (exec[i] && status >= 0)
			{
				cmd = ft_strsplit_fct(exec[i++], *ft_isspace);
				status = m_exec(cmd);
				ft_array_free(cmd);
			}
			free(line);
			ft_array_free(exec);
		}
	}
}
