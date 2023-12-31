NAME		= philo

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -g -pthread

ifeq ($(MAKECMDGOALS), thread)
	CFLAGS += -fsanitize=thread
endif

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -fsanitize=address
endif

SRC_PATH	= srcs
SRC			= main.c \
				action.c \
				check_arg.c \
				monitor.c \
				philo_bool.c \
				philo_init.c \
				print.c \
				print_action.c \
				time.c \

SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:%.c=%.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH	= includes
INC			= philo.h
INCS		= $(addprefix $(INC_PATH)/, $(INC))

RM			= rm -f

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@ echo ""
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@ mkdir -p ./obj
	@ echo "$(CHECK) $(BLUE)Compiling Philosophers... $(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

clean:
	@ $(RM) -r ./obj/
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r ./obj/
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files and $(NAME).$(RESET)\n"

re: fclean all

debug: re

thread: re

.PHONY : all clean fclean re debug thread