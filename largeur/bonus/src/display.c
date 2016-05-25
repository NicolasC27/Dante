/*
** display.c for display.c in /home/cheval_8/rendu/dante/profondeur/bonus
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sun May 22 23:25:42 2016 Nicolas Chevalier
** Last update Sun May 22 23:28:39 2016 Nicolas Chevalier
*/

#include "ncurses.h"
#include "my.h"

static void	print_map(t_solver *maze, char **map, int y, int x)
{
  y = -1;
  while (++y < maze->width)
    {
      if (map[x][y] == WALL)
	{
	  attron(COLOR_PAIR(8));
	  printw(" ");
	}
      else if (map[x][y] == VISITED)
	{
	  attron(COLOR_PAIR(4));
	  printw(" ");
	}
      else if (map[x][y] == UNVISITED)
	{
	  attron(COLOR_PAIR(7));
	  printw(" ");
	}
      else if (map[x][y] == PATH)
	{
	  attron(COLOR_PAIR(1));
	  printw(" ");
	}
    }
}

void		display_ncurses(t_solver *maze, char **map)
{
  int		x;

  x = 0;
  erase();
  while (x < maze->height)
    {
      print_map(maze, map, 0, x);
      printw("\n");
      x += 1;
    }
}
