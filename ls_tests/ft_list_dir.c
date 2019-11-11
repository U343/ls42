

#include "ft_ls.h"

int 	main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*res;
	struct stat		buf;
	int 			p;
	char 			*time;

	if (ac > 2)
	{
		ft_putstr("error, to many files\n");
		return (0);
	}
	if (ac == 1)
	{
		if (!(dir = opendir(".")))
		{
			ft_putstr("error open directory '.'\n");
			return (0);
		}
	}
	else
	{
		if (!(dir = opendir(av[1])))
		{
			ft_putstr("error open directory ");
			ft_putstr(av[1]);
			ft_putchar('\n');
			return (0);
		}
	}
	while ((res = readdir(dir)))
	{
		if ((p = stat(res->d_name, &buf)) != 0)
		{
			ft_putstr("error stat\n");
			return (0);
		}
		time = asctime(localtime(&buf.st_ctime));
		ft_putstr(res->d_name);
		ft_putstr("  ");
		ft_putstr(time);
		//ft_putchar('\n');
	}
	closedir(dir);
	return (0);
}
