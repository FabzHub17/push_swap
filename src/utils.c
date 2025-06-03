#include "../includes/push_swap.h"

//char	*ft_strdup(const char *s);
//char **array_cpy(char **dest, char **src, int start_index, int size);

char **init_args(t_stack **stack, int ac, char **av)
{
    char **array;
    int i;

    i = 1;
    array = NULL;
    // if a num set is given within brackets
    if (ac == 2)
    {
        array = ft_split(av[1], ' ');
        if (!array)
            return (NULL);
    }
    else
         // if a num set is given as separate arguments
        array = av + 1; // Point to the first argument

    return(array);
}

static long	ft_atol(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}


/*
char **array_cpy(char **dest, char **src, int start_index, int size)
{
    int i;

    //Allocate memory for array is it's NULL
    if(!dest)
    {
        dest = (char **)malloc(sizeof(char *) * size);
        if(!dest)
            return(NULL);
    }
    // Copy elements from src to dest
    i = 0;
    while(i < size - start_index)
    {
        dest[i] = ft_strdup(src[start_index + i]);
        if (!dest[i])
        {
            // Free previously allocated memory in case of failure
            while (i > 0)
            {
                free(dest[i - 1]);
                i--;
            }
            free(dest);
            return;
        }
        i++;
    }
    dest[i] = NULL; // Null-terminate the array
    return (dest);

}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
    */