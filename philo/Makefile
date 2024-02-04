# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/04 16:40:24 by fras          #+#    #+#                  #
#    Updated: 2024/02/04 16:32:57 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
PHILO_SOURCES = $(shell find $(SRC_DIR)/ -type f -name "*.c")
PHILO_OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(PHILO_SOURCES:%.c=%.o))
RM = rm -f

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -g -fsanitize=thread -fsanitize-undefined-trap-on-error
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

philo: $(PHILO_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(PHILO_OBJECTS)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

mandatory: $(NAME)

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Debugging
debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"