NAME = fractol

CFLAGS =  -lmlx -framework OpenGL -framework AppKit #-g3 -fsanitize=address

DEPND =  src/init.c src/pars.c src/maps.c src/window.c

all : $(NAME)

$(NAME) : $(DEPND)
	cc $(CFLAGS) $(DEPND) -o $(NAME)
clean :
	rm -rf fractol
re : clean all