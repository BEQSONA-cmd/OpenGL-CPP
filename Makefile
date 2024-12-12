NAME = game
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lGL -lglfw -ldl -lglut

SRC = $(wildcard *.cpp) $(wildcard */**.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

run: all
	./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
