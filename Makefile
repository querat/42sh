##
## Makefile for  in /home/querat_g/42sh
## 
## Made by gwendal querat
## Login   <querat_g@epitech.net>
## 
## Started on  Thu Apr 23 11:01:43 2015 gwendal querat
## Last update Sun May 24 18:32:24 2015 guigui
##

LIB		= libmy.a

AR_RC		= ar rc

NAME		= 42sh

RANLIB		= ranlib

LIB_SRCS	= lib_src/convert_base.c \
		  lib_src/get_next_line.c \
		  lib_src/tab_len.c \
		  lib_src/get_option.c \
		  lib_src/is_option.c \
		  lib_src/listes.c \
		  lib_src/listes2.c \
		  lib_src/my_atoi.c \
		  lib_src/my_countnb_b.c \
		  lib_src/my_epur_str.c \
		  lib_src/my_find_prime_sup.c \
		  lib_src/my_get_el.c \
		  lib_src/my_getnbr.c \
		  lib_src/my_getnbr_base.c \
		  lib_src/my_isneg.c \
		  lib_src/my_is_prime.c \
		  lib_src/my_malloc.c \
		  lib_src/my_malloc2.c \
		  lib_src/my_parse.c \
		  lib_src/my_power_it.c \
		  lib_src/my_power_rec.c \
		  lib_src/my_printf.c \
		  lib_src/my_put.c \
		  lib_src/my_putblank.c \
		  lib_src/my_putchar.c \
		  lib_src/my_putchar2.c \
		  lib_src/my_putint.c \
		  lib_src/my_put_nbr.c \
		  lib_src/my_putnbr_base.c \
		  lib_src/my_putnbr_base2.c \
		  lib_src/my_putptr.c \
		  lib_src/my_putstr.c \
		  lib_src/my_putstr2.c \
		  lib_src/my_revstr.c \
		  lib_src/my_round.c \
		  lib_src/my_showmem.c \
		  lib_src/my_showstr.c \
		  lib_src/my_show_wordtab.c \
		  lib_src/my_sort_int_tab.c \
		  lib_src/my_square_root.c \
		  lib_src/my_strcapitalize.c \
		  lib_src/my_strcat.c \
		  lib_src/my_strcmp.c \
		  lib_src/my_strcpy.c \
		  lib_src/my_strdup.c \
		  lib_src/my_str_isalpha.c \
		  lib_src/my_str_islower.c \
		  lib_src/my_str_isnum.c \
		  lib_src/my_str_isprintable.c \
		  lib_src/my_str_isupper.c \
		  lib_src/my_strlcat.c \
		  lib_src/my_strlen.c \
		  lib_src/my_strlowcase.c \
		  lib_src/my_strnbr.c \
		  lib_src/my_strncat.c \
		  lib_src/my_strncmp.c \
		  lib_src/my_strncpy.c \
		  lib_src/my_strstr.c \
		  lib_src/my_strtab.c \
		  lib_src/my_strtok.c \
		  lib_src/my_str_to_wordtab.c \
		  lib_src/my_strupcase.c \
		  lib_src/my_swap.c \
		  lib_src/my_uppercase.c \
		  lib_src/worknb.c \
		  lib_src/file/get_ram.c \
		  lib_src/file/my_fdup.c \
		  lib_src/file/my_fgeti.c \
		  lib_src/file/my_fgetsize.c \
		  lib_src/file/my_fread.c \
		  lib_src/file/my_opcl.c \
		  lib_src/file/my_fwrite.c \
		  lib_src/print_binary.c \
		  lib_src/flip_endian.c \
		  lib_src/tab_len.c \
		  lib_src/gnl_querat_g.c \
		  lib_src/gen_flip_endian.c \
		  lib_src/hashtable.c \
		  lib_src/hashtable2.c \
		  lib_src/hashtable3.c \
		  lib_src/my_memcpy.c \
		  lib_src/my_ptrcmp.c \
		  lib_src/my_ptrdup.c \
		  lib_src/my_strndup.c

SRCS		= src/main.c \
                  src/openstate.c \
                  src/tty.c \
                  src/free_elem.c \
                  src/graphs/edges.c \
		  src/graphs/edges2.c \
		  src/graphs/add_node.c \
		  src/graphs/init_network.c \
		  src/graphs/brk_node.c \
		  src/graphs/find_node.c \
		  src/graphs/free_network.c \
		  src/graphs/print_network.c \
		  src/graphs/slist_create.c \
		  src/graphs/slist_destroy.c \
		  src/graphs/slist_util.c \
		  src/readline/dlist/dlist_len.c \
		  src/readline/dlist/dlist_create.c \
		  src/readline/dlist/dlist_destroy.c \
		  src/readline/dlist/dlist_util.c \
		  src/my_perror.c \
		  src/str_insert.c \
		  src/readline/modes.c \
		  src/readline/get_term_name.c \
		  src/readline/my_mem.c \
		  src/readline/readline_functab.c \
		  src/readline/readline.c \
		  src/readline/is_backspace.c \
		  src/readline/is_begkey.c \
		  src/readline/is_ctrlk.c \
		  src/readline/is_ctrll.c \
		  src/readline/is_ctrlr.c \
		  src/readline/is_ctrlu.c \
		  src/readline/is_ctrly.c \
		  src/readline/is_ctrl_left.c \
		  src/readline/is_ctrl_right.c \
		  src/readline/is_delete.c \
		  src/readline/is_downkey.c \
		  src/readline/is_endkey.c \
		  src/readline/is_leftkey.c \
		  src/readline/is_notascii.c \
		  src/readline/is_printable_char.c \
		  src/readline/is_rightkey.c \
		  src/readline/is_tab.c \
		  src/readline/is_upkey.c \
		  src/readline/is_alphanum.c \
		  src/readline/print_new_buffer.c \
		  src/readline/cursor_win_management.c \
		  src/exec/builtin.c \
		  src/exec/dupstdin.c \
		  src/exec/dupstdout.c \
		  src/exec/my_cd.c \
		  src/exec/my_cleancmd.c \
		  src/exec/my_exec_builtin.c \
		  src/exec/my_listenv.c \
		  src/exec/my_listenv2.c \
		  src/exec/my_listenv3.c \
		  src/exec/my_process.c \
		  src/exec/my_readstdin.c \
		  src/exec/my_resetsignals.c \
		  src/exec/my_setsignals.c \
		  src/exec/redfile.c \
		  src/exec/redirec.c \
		  src/exec/tests.c \
		  src/exec/my_getpath.c \
		  src/exec/my_getpath2.c \
		  src/exec/my_getabsolutepath.c \
		  src/exec/my_env.c \
		  src/exec/subexec.c \
		  src/exec/testprocess.c \
		  src/exec/subexecchild.c \
		  src/exec/subexecchild2.c \
		  src/exec/lastreturnvalue.c \
		  src/exec/execfcts3.c \
		  src/exec/execfcts.c \
		  src/exec/dored.c \
		  src/exec/testsred.c \
		  src/exec/convertlisttoexectab.c \
		  src/exec/echo_main.c \
		  src/exec/echo2.c \
		  src/exec/camarchepas_main.c \
		  src/exec/ghostbuster.c \
		  src/exec/subexecall.c \
		  src/tokenizer/tokenizer.c \
		  src/tokenizer/token_tab.c \
		  src/tokenizer/is_sp_right.c \
		  src/tokenizer/is_db_right.c \
		  src/tokenizer/is_sp_left.c \
		  src/tokenizer/is_db_left.c \
		  src/tokenizer/is_semicolon.c \
		  src/tokenizer/is_pipe.c \
		  src/tokenizer/is_oror.c \
		  src/tokenizer/is_and.c \
		  src/tokenizer/is_andand.c \
		  src/tokenizer/is_backslash.c \
		  src/tokenizer/is_db_quote.c \
		  src/tokenizer/is_sp_quote.c \
		  src/tokenizer/is_not_reserved_char.c \
		  src/tokenizer/epur_tok.c \
		  src/tokenizer/toggle_state.c \
		  src/tokenizer/get_word.c \
		  src/expander/expand_env_var.c \
		  src/expander/expand_globbing.c \
		  src/expander/get_globbed_str.c \
		  src/db_left.c \
		  src/parser/parser.c \
		  src/parser/do_redir.c \
		  src/parser/tok_types.c \
		  src/parser/parser_debug.c \
		  src/parser/slist_to_char_array.c \
		  src/parser/true_mem.c \
		  src/parser/rm_cur.c \

LIB_OBJS	= $(LIB_SRCS:.c=.o)

OBJS		= $(SRCS:.c=.o)

SAVS_HDS	= include/file.h~ \
		  include/format.h~ \
		  include/hashtable.h~ \
		  include/listes.h~ \
		  include/my.h~ \
		  include/my_mem.h~ \
		  include/my_printf.h~ \
		  include/str_to_wordtab.h~

SAVS_LIB	= $(LIB_SRCS:.c=.c~)

SAVS_PRJ	= $(SRCS:.c=.c~)

RM		= rm -f

CC		= gcc

CFLAGS		= -Wall -Wextra -I./include

LDFLAGS		= -lmy -L. -lncurses

all:		$(LIB) $(NAME)

$(LIB):		$(LIB_OBJS)
		$(AR_RC) $(LIB) $(LIB_OBJS)
		$(RANLIB) $(LIB)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) $(LIB_OBJS)
		$(RM) $(OBJS)
		$(RM) $(SAVS_LIB)
		$(RM) $(SAVS_PRJ)
		$(RM) Makefile~

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(ASM)
		$(RM) $(LIB)
		$(RM) $(DSM)

re:		fclean all

test:		re
		./test.sh

.PHONY: all clean fclean re test
