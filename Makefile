NAME	= clone

CC	= g++

RM	= rm -f

rwildcard  = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRCS	= $(call rwildcard,src,*.cpp)

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -I ./libs/ -g -Wall -Werror -Wextra -Wuninitialized
LINKERS = -lSDL2 -lGL

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LINKERS)

clean:
	$(RM) -f $(OBJ)
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.o' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete
	@find -type f -name '*.a' -delete
	@$(RM) -r -f *~ \#*\#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
