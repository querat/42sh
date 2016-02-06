/*
** file.h for  in /home/querat_g/42sh/include
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 23 11:00:20 2015 gwendal querat
** Last update Mon May  4 16:48:44 2015 gwendal querat
*/

#ifndef FILE_H_
# define FILE_H_

# define FILE_SZ_MAX 2147483648
# define BUFF_SZ 32768
# define UNIT_ERROR -1
# define BYTE 1
# define KBYTE 2
# define MBYTE 3
# define GBYTE 4
# define TBYTE 5
# define UBYTE "B"
# define UKBYTE "kB"
# define UMBYTE "MB"
# define UGBYTE "GB"
# define MEMTOTAL "MemTotal:"
# define MEMFREE "MemFree:"
# define MEMAVAILABLE "MemAvailable:"
# define NEOF 1
# define NOT_FLUSHED 0
# define FLUSHED 1

struct	s_ram
{
  int	unit;
  long	memtotal;
  long	memfree;
  long	memavailable;
};
struct s_file
{
  char	buff[BUFF_SZ + 1];
  char	*name;
  int	fmode;
  int	fd;
  int	csr;
  int	status;
  int	state;
};

typedef struct s_file t_fle;
typedef struct s_ram t_ram;

int	my_fdup(char *, char *);
int	my_fgeti(t_fle *);
long	my_fgetsize(char *);
int	my_fbuffncpy(char *, char *, int);
int	my_fread(t_fle *, char *, int);
int	my_fclose(t_fle *);
t_fle	*my_fopen(char *, int);
void	get_raminfo(t_ram *);
void	get_raminfoloop(t_ram *, char **, int);
int	get_memunit(char *);
size_t	my_fwrite(const void *, size_t, size_t, t_fle *);
void	my_flush(t_fle *);

#endif /* !FILE_H_ */
