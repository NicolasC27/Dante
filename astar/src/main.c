/*
** main.c for main.c in /home/cheval_8/rendu/dante/profondeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sun May  1 20:59:34 2016 Nicolas Chevalier
** Last update Sun May 22 22:58:47 2016 Nicolas Chevalier
*/

#include "my.h"

static void	display(t_solver *maze, char **map)
{
  int		x;
  int		y;

  x = 0;
  while (x < maze->height)
    {
	y = 0;
	while (y < maze->width)
	  {
	    if (map[x][y] && map[x][y] == WALL)
	      my_putstr("X");
	    else if (map[x][y] == VISITED || map[x][y] == UNVISITED)
	      my_putstr("*");
	    else if (map[x][y] == PATH)
	      my_putstr("o");
	    y += 1;
	  }
	x += 1;
	if (x < maze->height)
	  my_putstr("\n");
    }
}

static void	a_star(char *file)
{
  t_solver	maze;
  t_list	list;
  char		**map;

  map = parser(file, &maze);
  init_list(&list);
  map = algorithm(&list, &maze, map, NULL);
  if (map == NULL)
    {
      my_putstr("No solution found\n");
      exit (0);
    }
  display(&maze, map);
}

static void	help(void)
{
  my_putstr("Manuel program:\n\n");
  my_putstr("./solver [fichier]\n");
  exit (0);
}

int		main(int argc, char **argv)
{
  if (argc != 2)
    help();
  a_star(argv[1]);
  return (0);
}
