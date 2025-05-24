#include "../includes/push_swap.h"

char **init_args(int ac, char **av)
{
    char **array;
    int i;

    i = 1;
    if (ac == 2)
    {
        array = ft_split(av[1], ' ');
        if (!array)
            return (NULL);
    }

    while (i < ac)
    {
        array = array_cpy(array, av[i]);
        if (!array)
            return (NULL);
        i++;
    }
    return (array);
}

char **array_cpy(char **array1, char **array2)
{
    char **new_array;
    int i;
    int j;

    i = 0;
    j = 0;
    while (array1[i])
        i++;
    while (array2[j])
        j++;
    new_array = malloc(sizeof(char *) * (i + j + 1));
    if (!new_array)
        return (NULL);
    i = 0;
    j = 0;
    while(array1[i])
    {
        new_array[i] = array1[i];
        i++;
    }
    while(array2[j])
    {
        new_array[j] = array2[j];
        j++;
    }
    new_array[i + j] = NULL;

    return (new_array);
}
