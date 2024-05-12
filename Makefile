NAME = fractol

CFLAGS =  -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

DEPND =  src/init.c src/pars.c src/maps.c src/window.c  fractol.c src/events.c src/drawing.c

all : $(NAME)

$(NAME) : $(DEPND)
	cc -O3 $(CFLAGS) $(DEPND) -o $(NAME)
clean :
	rm -rf fractol
re : clean all