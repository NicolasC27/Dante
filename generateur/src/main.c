/*
** main.c for main.c in /home/cheval_8/rendu/dante/src
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Apr 22 22:06:21 2016 Nicolas Chevalier
** Last update Sat May 21 07:11:35 2016 Nicolas Chevalier
*/

#include <stdbool.h>
#include <time.h>
#include "my.h"

void		help(void)
{
  my_putstr_err("Program Manuel:\n\n");
  my_putstr_err("./generateur [hauteur > 1] [largeur > 1] [parfait|imparfait]");
  my_putstr_err("\nThe program writes to standard output.\n");
  exit (EXIT_SUCCESS);
}

/*
** Function display the map
*/
static void	display(t_maze *data)
{
  int		i;
  int		z;

  i = 0;
  while (i < data->height)
    {
      z = 0;
      while (z < data->width)
      	{
      	  if (data->maze[i][z] == WALL)
	    my_putstr("X");
	  else if (data->maze[i][z] == VISITED)
	    my_putstr("*");
	  else
	    my_putstr("X");
	  z += 1;
	}
      i += 1;
      if (i < data->height)
	my_putstr("\n");
    }
}

static void	generateur(char **argv)
{
  t_maze	data;
  t_list	list;

  init_list(&list);
  parser(&data, argv);
  start_maze(&data, &list);
  display(&data);
}

int		main(int argc, char **argv)
{
  if (argc != 4)
    help();
  generateur(&argv[1]);
  return (0);
}
