NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -MMD

SRCS_DIR = srcs
INCLUDES_DIR = includes
BUILD_DIR = build

SRCS = $(SRCS_DIR)/main.cpp \
       $(SRCS_DIR)/ScalarConverter.cpp

OBJS = $(patsubst $(SRCS_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)🟢 [$(NAME)] is built and ready to shine ✨$(NC)"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

-include $(DEPS)

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		rm -rf $(BUILD_DIR); \
		echo "$(RED)❌ Object files and build directory removed$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)❌ Executable [$(NAME)] removed$(NC)"; \
	fi

re: fclean all

test: $(NAME)
	@echo "\n$(GREEN)=== Running tests ====$(NC)"
	@echo "\n--- Valid literals ---"
	@./$(NAME) "0"
	@./$(NAME) "nan"
	@./$(NAME) "42.0f"
	@./$(NAME) "-42"
	@./$(NAME) "+inf"
	@./$(NAME) "-inff"
	@./$(NAME) "a"       
	@./$(NAME) "'a'"     

	@echo "\n--- Large and edge cases ---"
	@./$(NAME) "999999999999999999999999"  
	@./$(NAME) "2147483648"        
	@./$(NAME) ""

	@echo "\n--- Strange / leftover tests ---"
	@./$(NAME) "42.0fdasd"  
	@./$(NAME) "42.0ff"     
	@./$(NAME) "nanf42"     
	@./$(NAME) "42a"  
	@./$(NAME) "'ab'"     
	@./$(NAME) "hello"    


.PHONY: all clean fclean re
