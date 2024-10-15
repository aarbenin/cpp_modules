CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

NAME = bank
INCLUDES = Account.hpp
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)
	@true

$(NAME): $(OBJ)
	@echo "$(GREEN)🛠 Building project...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] is built and ready to shine!✨$(NC)"

$(OBJ): %.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if ls $(OBJ) 1> /dev/null 2>&1; then \
		rm -f $(OBJ); \
		echo "$(RED)🧹 Object files cleaned up!$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)🗑️ Executable [$(NAME)] removed! 💔 Farewell, brave binary!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re