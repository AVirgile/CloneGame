NAME	= clone

CC	= g++

RM	= rm -f

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRCS	= $(call rwildcard,src,*.cpp)

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -g -Wall -Werror -Wextra -Wuninitialized
LINKERS = -lSDL2 -lGL

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LINKERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
