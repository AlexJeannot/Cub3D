#include "../includes/second_cube.h"

int	ft_atoi_cub(const char *nb)
{
	int	cmp;
	int	nb_final;

	cmp = 0;
	nb_final = 0;
  while (nb[cmp] > 47 && nb[cmp] < 58)
    {
    	nb_final = (nb_final * 10) + (nb[cmp] - 48);
    	cmp++;
    }
  return (nb_final);
}

char	*ft_strjoin_cub(char *str_1, char *str_2, int len_1, int len_2)
{
	int		cmp;
	char	*output_str;

	if (!(output_str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 2))))
    return (NULL);
	cmp = 0;
	if (str_1)
		while (str_1[cmp])
		{
			output_str[cmp] = str_1[cmp];
			cmp++;
		}
	cmp = 0;
	while (str_2[cmp])
	{
		output_str[cmp + len_1] = str_2[cmp];
		cmp++;
	}
	output_str[cmp + len_1] = '\n';
	output_str[cmp + len_1 + 1] = '\0';
	if (str_1)
		free(str_1);
	return (output_str);
}

int ft_strlen(char *str)
{
	int cmp;

	cmp = 0;
	if (str)
		while (str[cmp])
			cmp++;
	return (cmp);
}

int ft_strlen_without_space(char *str)
{
	int cmp;
	int cmp_2;

	cmp = 0;
	cmp_2 = 0;
	if (str)
		while (str[cmp])
		{
			if (str[cmp] != ' ')
			{
				cmp++;
				cmp_2++;
			}
			else
				cmp++;
		}
	return (cmp_2);
}
