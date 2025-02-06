/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:37:39 by galauren          #+#    #+#             */
/*   Updated: 2025/02/06 10:14:07 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	if (s1[i] == s2[i])
		return (0);
	if (s1[i] < s2[i])
		return (-1);
	return (1);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("le MIEN : %d\n", ft_strcmp("", "8salttte"));
	printf("le LEUR : %d\n", strcmp("", "8salttte"));
}*/
