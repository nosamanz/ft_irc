CPPFLAG = -Wall -Wextra -Werror -std=c++98
# CPPFLAGS = -std=c++98
SRC = src/*.cpp src/cmnds/*.cpp
HDR = inc/*.hpp
NAME = ircserv
CC = c++

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CPPFLAG) $(SRC) -o $(NAME)
	@echo compiled!
clean:
	@echo cleaned

fclean: clean
	@rm -rf $(NAME)

re: fclean all