# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/04 16:40:24 by fras          #+#    #+#                  #
#    Updated: 2023/12/06 15:47:58 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include -I $(EXTLIB_DIR)/include
SRC_DIR = src
OBJ_DIR = obj
PHILO_SOURCES = $(shell find $(SRC_DIR)/philo -type f -name "*.c")
PHILO_OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(PHILO_SOURCES:%.c=%.o))

RM = rm -f

# Libraries
LIB_DIR = lib
EXTLIB_DIR = $(LIB_DIR)/libs42
LIBRARIES = $(addprefix $(LIB_DIR)/, libft.a)

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

philo: $(LIBRARIES) $(PHILO_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(PHILO_OBJECTS) $(LIBRARIES)
	@$(MAKE) message EXECUTABLE=$@

philo_bonus: $(LIBRARIES) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(BONUS_OBJECTS) $(LIBRARIES)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

mandatory: $(NAME)

bonus: $(BONUS)

# Libraries
$(LIBRARIES): $(EXTLIB_DIR)/$(@F)
	$(MAKE) -C $(EXTLIB_DIR) $(@F)
	cp $(EXTLIB_DIR)/$(@F) $@

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(MAKE) -C $(EXTLIB_DIR) $@
	$(RM) $(LIBRARIES)
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

# Submodule functions
initialize_submodules:
	git submodule update --init --recursive
	git submodule foreach --recursive git checkout master

update_submodules:
	git submodule update --recursive
	git submodule foreach --recursive git fetch
	git submodule foreach git merge origin master