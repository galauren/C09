int	ft_strlen(char *str)
{
	int i;

	i = -1;
	while(str[++i] != '\0')
		;
	return (i);
}
