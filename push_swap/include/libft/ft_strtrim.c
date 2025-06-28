/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:29:08 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 14:26:26 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char *to_trim, char *set)
{
	unsigned int	t_ind;
	unsigned int	set_ind;
	unsigned int	count;

	t_ind = 0;
	set_ind = 0;
	count = 0;
	while (set[set_ind])
	{
		while (to_trim[t_ind])
		{
			if (to_trim[t_ind] == set[set_ind])
				count++;
			t_ind++;
		}
		t_ind = 0;
		set_ind++;
	}
	return (count);
}

char	*ft_strtrim(char const *to_trim, char const *set)
{
	char			*str;
	unsigned int	tt_len;
	unsigned int	count;
	int				start;
	int				end;

	count = ft_size((char *)to_trim, (char *)set);
	tt_len = ft_strlen(to_trim);
	end = tt_len;
	start = 0;
	if (tt_len == 0)
		return (ft_strdup(""));
	while (to_trim[start] && ft_strchr(set, to_trim[start]))
		start++;
	while (start < end && ft_strchr(set, to_trim[end - 1]))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (start < end)
		str[count++] = to_trim[start++];
	str[count] = 0;
	return (str);
}
