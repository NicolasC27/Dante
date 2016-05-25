/*
** main.c for main.c in /home/cheval_8/rendu/dante/profondeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sun May  1 20:59:34 2016 Nicolas Chevalier
** Last update Sun May 22 22:54:24 2016 Nicolas Chevalier
*/

#include "my.h"

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
      endwin();
      my_putstr("No solution found\n");
      exit (0);
    }
  display_ncurses(&maze, map);
  getch();
  pause();
  endwin();
}

static void	help(void)
{
  my_putstr("Manuel program:\n\n");
  my_putstr("./solver [fichier]\n");
  exit (0);
}

void		init_ncurses()
{
  int		i;

  i = 0;
  nodelay(initscr(), TRUE);
  start_color();
  while (i < COLORS && i < COLOR_PAIRS)
    {
      init_pair(i, COLOR_BLACK, i);
      i += 1;
    }
  cbreak();
  curs_set(0);
  noecho();
}

int		main(int argc, char **argv)
{
  if (argc != 2)
    help();
  init_ncurses();
  a_star(argv[1]);
  return (0);
}
