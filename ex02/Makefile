CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

NAME = bank
INCLUDES = Account.hpp
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m # No Color

all: $(NAME)
	@echo -e "$(GREEN)🚀 Building project...$(NC)"

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)✅ Executable $(NAME) created successfully!$(NC)"

clean:
	@rm -f $(OBJ)
	@echo -e "$(RED)🧹 Object files cleaned up!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(RED)🗑️ Executable $(NAME) removed! Farewell, brave binary!$(NC)"

re: fclean all
	@echo -e "$(GREEN)🔄 Rebuilt everything from scratch!$(NC)"

.PHONY: all clean fclean re