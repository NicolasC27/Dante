/*
** parser.c for parser.c in /home/cheval_8/rendu/dante/generateur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri May 20 00:22:37 2016 Nicolas Chevalier
** Last update Sun May 22 23:02:45 2016 Nicolas Chevalier
*/

#include <string.h>
#include "my.h"

static void	get_arguments(t_maze *data, char **argv)
{
  data->width = my_getnbr(argv[0]);
  data->height = my_getnbr(argv[1]);
  data->type = 0;
  if (strcmp(argv[2], "parfait") == 0)
    data->type = PARFAIT;
  else if (strcmp(argv[2], "imparfait") == 0)
    data->type = IMPARFAIT;
  if (data->type == 0 || data->width < 2 || data->height < 2)
    help();
}

static void	prepare_generating(t_maze *data)
{
  int		i;
  int		z;

  if ((data->maze = malloc(sizeof(char *) * (data->height + 2))) == NULL)
    exit (0);
  i = 0;
  while (i < data->height)
    {
      if ((data->maze[i] = (char *)malloc(sizeof(char) *
					  data->width + 10)) == NULL)
	exit (0);
      z = 0;
      while (z < data->width - 1)
	{
	  data->maze[i][z] = UNVISITED;
	  z += 1;
	}
      data->maze[i][z] = '\0';
      i += 1;
    }
  if ((data->maze[i] = (char *)malloc(sizeof(char) * 1)) == NULL)
    exit (0);
  data->maze[i][0] = '\0';
}

void		parser(t_maze *data, char **argv)
{
  get_arguments(data, argv);
  prepare_generating(data);
}
