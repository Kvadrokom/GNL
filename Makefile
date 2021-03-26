Src_bon := get_next_line_bonus.c\
			get_next_line_utils_bonus.c

Obj_bon := $(patsubst %.c, %.o, $(Src_bon))

CC := gcc -g

bs := 9999

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

override bs := $(bs)

Flags := -Wall -Wextra -Werror -D BUFFER_SIZE=$(bs) main_bonus.c 

all :
	$(CC) $(Flags) $(Src_bon)