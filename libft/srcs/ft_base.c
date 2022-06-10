#include "libft.h"

size_t  ft_countlen(unsigned long long nb, char *base)
{
        size_t  i;

        i = 0;
        if (nb == 0)
                return (1);
        while (nb != 0)
        {
                nb /= ft_strlen(base);
                i++;
        }
        return (i);
}

char    *makebase(unsigned long long nb, char *base, char *str)
{
        size_t  i;

        i = ft_countlen(nb, base);
        str[i--] = 0;
        if (nb == 0)
                str[i] = 48;
        else
        {
                while (nb != 0)
                {
                        str[i] = base[nb % ft_strlen(base)];
                        nb /= ft_strlen(base);
                        i--;
                }
        }
        return (str);
}

char    *ft_itoa_base(unsigned long long nb, char *base)
{
        char    *str;

        str = malloc(sizeof(char) * ft_countlen(nb, base) + 1);
        if (!str)
                return (NULL);
        str = makebase(nb, base, str);
        return (str);
}

int     ft_index_base(int nb, char *base)
{
        int     i;

        i = 0;
        while (base[i])
        {
                if (base[i] == nb)
                        return (i);
                i++;
        }
        return (-1);
}

int     ft_atoi_base(const char *str, char *base)
{
        int     res;
        int     i;

        i = 0;
        res = 0;
        if (!str)
                return (-1);
        while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        while (str[i])
        {
                res *= ft_strlen(base);
                res += ft_index_base(str[i], base);
                i++;
        }
        return (res);
}