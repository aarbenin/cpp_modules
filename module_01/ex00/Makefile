CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

NAME = BraiiiiiiinnnzzzZ

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)
	@true

$(NAME): $(OBJS)
	@echo "🛠 $(GREEN)Summoning the undead...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] is built and ready to rise! 🧟✨$(NC)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if ls $(OBJS) 1> /dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "$(RED)🧩 Cleaning up zombie remains...$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)🗑️ Executable [$(NAME)] removed 💔 Rest in peace, brave binary!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re