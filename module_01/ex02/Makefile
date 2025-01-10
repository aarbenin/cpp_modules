NAME = this_is_brain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)🟢 [$(NAME)] is built and ready to rise! 🧟✨$(NC)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if [ -n "$(OBJS)" ] && ls $(OBJS) 1> /dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "$(RED)❌ Object files removed$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)❌ Executable [$(NAME)] removed$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
