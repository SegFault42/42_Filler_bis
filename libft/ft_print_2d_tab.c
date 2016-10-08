#include "./includes/libft.h"

void	ft_print_2d_tab(char **tab, int size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size_y)
	{
		while (tab[j][i] != '\0')
		{
			ft_putchar(tab[j][i]);
			i++;
		}
			ft_putchar('\n');
		j++;
		i = 0;
	}
}
