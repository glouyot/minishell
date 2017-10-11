/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouyot <glouyot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:11:38 by glouyot           #+#    #+#             */
/*   Updated: 2017/10/11 15:07:08 by glouyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define NBR_BUILTINS (int)8

typedef struct	s_blts
{
	char		name[32];
	int			(*f)(char **args);

}				t_blts;

typedef struct	s_env
{
	char		**key;
	char		**value;
}				t_env;

int				ft_cd(char **av);
int				ft_echo(char **av);
int				ft_setenv(char **av);
int				ft_unsetenv(char **av);
int				ft_getenv(char **av);
int				ft_env(char **av);
int				ft_exit(char **av);
int				ft_help(char **av);

t_blts			*blts(void);
t_env			*ft_initenv(char **env);
void			m_loop(void);
int				m_exec(char **cmd);
int				ft_inenv(char *key, t_env *env);
void			ft_delenv(void);
char			**ft_envchar(void);
char			*ft_getstrenv(char *cmd);
void			ft_errornoenv(char *env);
void			ft_cleanenv(t_env *env);
void			signals(int);
void			ft_prompt();

#endif
