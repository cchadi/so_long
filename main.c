/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:52 by csaidi            #+#    #+#             */
/*   Updated: 2024/03/24 12:36:52 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_extention(char *arg)
{
	char	*str;
	int		i;

	if (ft_strchr(arg, '.') == NULL)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '.')
			break ;
		i++;
	}
	str = ft_substr(arg, i, ft_strlen(arg));
	return (str);
}

int	main(int ac, char **av)
{
	t_texture	t;
	char		*ext;
	int			fd;

	if (ac > 2)
	{
		ft_printf("Error\n more than two parameter\n");
		return (0);
	}
	ext = check_extention(av[1]);
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".ber", ft_strlen(".ber")) != 0)
	{
		ft_printf("Error\nuse '.ber' as extention\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	t.map = valide_map(fd);
	if (t.map == NULL)
	{
		ft_printf("Error\nmap non valide\n");
		return (0);
	}
	open_window(t);
}
