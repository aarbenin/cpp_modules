CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

NAME = phonebook
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)
	@true

$(NAME): $(OBJS)
	@echo "$(GREEN)🛠 Building project...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] is built and ready to shine!✨$(NC)"

$(OBJS): %.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if ls $(OBJS) 1> /dev/null 2>&1; then \
		rm -f $(OBJS); \
		echo "$(RED)🧹 Object files cleaned up!$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)🗑️ Executable [$(NAME)] removed! 💔 Farewell, brave binary!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re