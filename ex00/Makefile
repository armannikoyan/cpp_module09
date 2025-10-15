NAME        := btc

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -MMD -MP
CPPFLAGS    := -I.
LDFLAGS     :=

SRCS        := main.cpp BitcoinExchange.cpp
OBJS        := $(SRCS:.cpp=.o)
DEPS        := $(OBJS:.o=.d)

RED         := \033[0;31m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
BLUE        := \033[0;34m
NC          := \033[0m

DONE_CHAR   := $(GREEN)✓$(NC)
OBJ_CHAR    := $(BLUE)●$(NC)

.DEFAULT_GOAL := all

all: $(NAME)
	@printf "$(DONE_CHAR) Project $(NAME) ready\n"

$(NAME): $(OBJS)
	@printf "$(YELLOW)⚡ Linking $(NAME)...$(NC)\n"
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@printf "$(DONE_CHAR) Executable built: $(GREEN)$@$(NC)\n"

%.o: %.cpp
	@printf "$(OBJ_CHAR) Compiling $(notdir $<)...\n"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	@printf "$(RED)♻️  Cleaning object files...$(NC)\n"
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@printf "$(RED)♻️  Removing $(NAME)...$(NC)\n"
	@$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g3 -O0
debug: all
	@printf "$(DONE_CHAR) Debug build complete\n"

help:
	@echo "Available targets:"
	@echo "$(GREEN)all$(NC)     - Build project (default)"
	@echo "$(GREEN)clean$(NC)   - Remove object files"
	@echo "$(GREEN)fclean$(NC)  - Remove object files and executable"
	@echo "$(GREEN)re$(NC)      - Rebuild project"
	@echo "$(GREEN)debug$(NC)   - Build with debug symbols"
	@echo "$(GREEN)help$(NC)    - Show this help message"

.PHONY: all clean fclean re debug help
