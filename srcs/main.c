/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/11 18:12:33 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char	*g_last_value = NULL;
char	*g_last_key = NULL;

void	add_to_table(t_list **table, t_data *data, ssize_t const len)
{
	ft_lstadd_back(&(table[hash(data->key, SIZE_DATABASE, len)]),
		ft_lstnew(data));
}

void	find_value(t_list **table, char *key, ssize_t const len)
{
	t_list			*tmp;
	unsigned int	h;

	if (g_last_key && key && !strcmp(g_last_key, key))
	{
		printf("%s\n", g_last_value);
		return ;
	}
	h = hash(key, SIZE_DATABASE, len);
	if (table[h])
	{
		tmp = table[h];
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
			{
				g_last_key = key;
				g_last_value = get_data(tmp)->value;
				printf("%s\n", g_last_value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	printf("%s%s\n", key, ": Not found");
}

void	remove_from_table(t_list ***table, char *key, ssize_t const len)
{
	t_list			*tmp;
	unsigned int	h;
	t_list			*to_del;

	g_last_key = NULL;
	h = hash(key, SIZE_DATABASE, len);
	if ((*table)[h])
	{
		tmp = (*table)[h];
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
			{
				to_del = ft_lstremove_one(&((*table)[h]), tmp);
				free_data(to_del->content);
				free(to_del);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	process(t_list **table, char *line, ssize_t ret)
{
	size_t	length_key;
	char	type;
	t_data	*data;
	char	*key;

	--ret;
	line[ret] = 0;
	type = type_entry(line, &length_key);
	if (type == ENTRY)
	{
		key = strndup(line, length_key);
		if (!is_in_table(table, key, length_key))
		{
			set_data(&data, line, length_key);
			add_to_table(table, data, length_key);
			free(key);
			return ;
		}
		free(key);
	}
	else if (type == SEARCH)
		find_value(table, line, ret);
	else if (type == DELETE)
		remove_from_table(&table, &line[1], ret - 1);
}

int	main(int argc, char const *argv[])
{
	t_list	**table;
	char	*line;
	ssize_t	ret;

	if (argc != 1)
		return (0);
	(void) argv;
	table = init_table();
	line = NULL;
	ret = getline(&line, (size_t *)&ret, stdin);
	while (ret >= 0)
	{
		process(table, line, ret);
		line = NULL;
		ret = getline(&line, (size_t *)&ret, stdin);
	}
	if (line)
		free(line);
	free_table(table);
	return (0);
}
