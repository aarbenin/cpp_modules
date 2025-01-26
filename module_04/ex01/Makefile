NAME = brain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -MMD

SRCS_DIR = srcs
INCLUDES_DIR = includes
BUILD_DIR = build

SRCS = $(SRCS_DIR)/main.cpp \
       $(SRCS_DIR)/Animal.cpp \
       $(SRCS_DIR)/Cat.cpp \
       $(SRCS_DIR)/Dog.cpp \
       $(SRCS_DIR)/Brain.cpp

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
	@echo "$(GREEN)🟢 [$(NAME)] is built and ready to shine ✨🐾$(NC)"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

-include $(DEPS)

clean:
	@if ls $(BUILD_DIR)/*.o 1> /dev/null 2>&1; then \
		rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d; \
		rmdir $(BUILD_DIR); \
		echo "$(RED)❌ Object files removed$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)❌ Executable [$(NAME)] removed$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
