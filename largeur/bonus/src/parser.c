/*
** parser.c for parser.c in /home/cheval_8/rendu/dante/largeur
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Sat May 21 03:06:23 2016 Nicolas Chevalier
** Last update Sun May 22 23:05:33 2016 Nicolas Chevalier
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include "my.h"

static char	**get_first_line(int fd, t_solver *maze, char ***map)
{
  char		*buff;
  int		j;
  int		i;
  int		len;

  j = 0;
  i = 0;
  if ((buff = malloc(sizeof(char) * 1)) == NULL)
    exit (0);
  while ((len = read(fd, buff, 1)) > 0)
    {
      maze->width += 1;
      if (buff[0] == '\n')
	break ;
      (*map)[j] = my_realloc((*map)[j], 2);
      (*map)[j][i] = buff[0];
      (*map)[j][i + 1] = '\0';
      i += 1;
    }
  if (!(*map)[j])
    exit (0);
  (*map)[j++][i] = '\0';
  free(buff);
  return (*map);
}

static char	**get_lines(int fd, t_solver *maze, char ***map)
{
  char		*buff;
  int		j;
  int		size;
  int		len;

  j = 1;
  size = 2;
  if ((buff = malloc(sizeof(char) * maze->width + 1)) == NULL)
    exit (0);
  while ((len = read(fd, buff, maze->width)) > 0)
    {
      buff[((buff[len - 1] == '\n') ? (len - 1) : (len))] = '\0';
      size += 1;
      if (((*map) = (char **)realloc((*map), sizeof(char *) * (size))) == NULL)
      	exit (0);
      (*map)[j] = NULL;
      if (((*map)[j] = realloc((*map)[j], sizeof(char) * maze->width)) == NULL)
      	exit (0);
      strcpy((*map)[j], buff);
      maze->height += 1;
      j += 1;
    }
  free(buff);
  (*map)[j] = '\0';
  return (*map);
}

static char	**get_file(char *file, t_solver *maze)
{
  char		**map;
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    exit (0);
  map = NULL;
  maze->height = 0;
  maze->width = 0;
  if ((map = malloc(sizeof(char *) * 2)) == NULL)
    exit (0);
  map[0] = NULL;
  get_first_line(fd, maze, &map);
  maze->height += 1;
  map[1] = NULL;
  get_lines(fd, maze, &map);
  maze->width -= 1;
  return (map);
}

char		**parser(char *file, t_solver *maze)
{
  return (get_file(file, maze));
}
