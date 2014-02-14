#include <fcntl.h>

void	rtv1(char *scene)
{
	init_scene(scene);
	display_scene();
}

void	init_scene(char *scene)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_error("fichier incorrect");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// TODO : definir la structure des fichiers scène.
	}
}

void	display_scene()
{
	
}