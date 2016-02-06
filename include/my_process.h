/*
** my_process.h for mysh in /home/pirou_g/minishell2/include
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:26:13 2015 Guillaume Pirou
** Last update Sun May 24 13:13:58 2015 guigui
*/

#ifndef MY_PROCESS_H_
# define MY_PROCESS_H_

# define NOT_STARTED 1
# define RUNNING     2
# define FINISHED    3

# define EXIST       1
# define EXECUTABLE  2
# define NOT_FOUND   0

# define R_NO 0
# define R_RIGHT 1
# define R_LEFT 2
# define R_RRIGHT 3
# define R_LLEFT 4
# define R_PIPE 6

# define TPIPE 1
# define TBTIN 2
# define TSUBPG 3
# define TEXERN 4

# define NOCDT 0
# define SCCDT 1
# define FLCDT 2

# define CDENV 1
# define SETENV 2
# define UNSETENV 3
# define EXITENV 4

#include <unistd.h>
#include "dlist.h"

struct		s_lnv
{
  char		*name;
  char		*value;
  struct s_lnv	*prev;
  struct s_lnv	*next;
};

typedef struct s_lnv t_lnv;

struct	s_env
{
  char	*name;
  char	*value;
};

typedef struct s_env t_env;

struct s_cmd
{
  char *cmd;
  char *filen;
  int  red;
};

typedef struct s_cmd t_cmd;

struct	s_pcs
{
  char	*pathn;
  char	**args;
  int	stdout;
  int	stdin;
  int	stderr;
  int	redright;
  int	redleft;
  int	*pipedleft;
  int	*pipedright;
  char	*filout;
  char	*filin;
  char	*filerr;
  int	state;
  int	status;
  pid_t	pid;
  char	*wk_dir;
  char	**env;
  int	is_piped;
  int	cdt;
  int	retv;
  int	ret;
  int	sig;
};

typedef struct s_pcs t_pcs;

struct  s_dck
{
  t_pcs	*ptr;
  int   n;
};

typedef struct s_dck t_dck;

struct		s_tls
{
  void		*ptr;
  struct s_sys	*prev;
  struct s_sys	*next;
  int		type;
};

typedef struct s_tls t_tls;

struct	s_ins
{
  char	*cmd;
  char	**argv;
  char	**env;
  char	*file;
  t_pcs	pcs;
};

typedef struct s_ins t_ins;

struct	s_sys
{
  char	**strins;
  t_env	**env;
  int	n_ins;
  t_ins	*ins;
};

typedef struct s_sys t_sys;

struct	s_app
{
  char	*pathn;
  char	**args;
  char	**env;
  char  *filen;
  int   red;
};

typedef struct s_app t_app;

void	free_app(t_app *);
t_app	*my_getapp(char *, char **);
void	my_putapp(t_app *);
void	my_cleancmd(char *);
int	can_i_run_it(char *, char **);
int	is_built_in(char *);
char	**get_builtinstab();
void	del_envitem2(t_lnv *, t_lnv *);
void	del_envitem(t_lnv *);
int	add_envitem(t_lnv *, char *, char *);
void   	my_unsetenv(t_lnv *, char *);
void	my_setenv(t_lnv *, char *, char *);
void   	my_env(t_lnv *);
int	my_cntargs(t_app *);
void	my_cd2(t_lnv *, char *, char *, char *);
void   	my_cd(t_lnv *, char *);
int	my_exec_built_in2(t_app *);
void	my_exec_built_in(t_app *);
t_lnv	*convert_envtab(char **);
int	my_getenvnbitems(t_lnv *);
char	**convert_envtotab(t_lnv *);
void	free_envlist(t_lnv *);
void	disp_envlist(t_lnv *);
int	set_value(t_lnv *, char *, char *);
char	*get_value(t_lnv *, char *);
int	set_envitem(t_lnv *, char *);
void   	my_kill(t_pcs *);
void   	my_stop(t_pcs *);
t_pcs	*new_process(char *, char **);
void	free_process(t_pcs *);
char	*my_readstdinloop(char *, char *);
char	*my_readstdin();
void	my_builtinsinit(t_lnv *);
void   	my_exitshell(t_lnv *);
void	my_defaultexit();
void	my_resetsignals(t_lnv *);
void   	my_stoppcs(pid_t);
void	my_stopchild();
void	my_setsignals(pid_t);
void	my_exec(t_app *);
void	my_system(char *, char **);
void	my_system4(char *, char **, char *, int);
int	can_i_run_rel(char *);
int	is_cdpathdir(char *);
int	my_dupstdincat(char *);
int	my_dupstdin(char *);
int	my_duptruncstdout(char *);
int	my_dupstdout(char *);
t_cmd	*get_cmd(char *);
t_cmd	*get_cmd2(char *, int, char **, t_cmd *);
t_cmd	*get_cmd2(char *, int, char **, t_cmd *);
int	my_elsecreteoropen(char *);
int	my_wcreate_or_open(char *, int);
int	get_redirection(int, int, int);
void	my_system2(t_cmd *, char **);
void	my_system3(char **, char **);
int     count_pcs(t_pcs []);
int     exist_file(char *);
int     my_creatfile(char *);
int     is_directory(char *);
int     do_leftred(t_pcs [], int);
int     do_rightred(t_pcs [], int);
int     do_redirect(t_pcs [], int);
int     returncdt_checked(t_pcs [], int);
void    close_pipe(int [2]);
char    **init_shellinstab();
char    **get_shellins();
int     is_shellin(t_pcs *, char **);
void    raw_exec(t_pcs *);
int     is_executable(char *);
void    sh_envdelete(t_pcs *);
void    sh_env(t_pcs *);
void    exec_shellin(t_pcs *);
void    exec_subpgrm(t_pcs *);
void    exec_builtin(t_pcs *);
int     my_execchild(t_pcs [], int);
int     update_data(t_pcs *);
int     my_execparent(t_pcs [], int);
int     my_execone(t_pcs [], int);
int     my_execall(t_pcs [], t_lnv *);
t_pcs   *convertlisttoexectab(t_dlist *, int);
t_dck   *get_ghosts(t_pcs [], int);
void    dezombificator2(int);
int     camarchepas_main(int, char **, char **);
int     gg_ping(int, char **);
int     test_network(pid_t, int, char **, char *[3]);
void    free_execmem(t_pcs []);
void    show_pcstab(t_pcs []);
int     is_open(int *);
void    set_openstate(int *, int);
void    init_open();
void    init_lastreturnvalue();
int     set_lastreturnvalue(int *, int);
int     get_lastreturnvalue(int *);
void    show_strsignal(int);
void    dezombificator(t_pcs [], int);
int     count_cmdels(t_dlist *);
int	my_tty(int);

#endif
