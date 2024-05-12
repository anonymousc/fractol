NAME = fractol

CFLAGS = -Werror -Wextra -Wall

MLXFLGS =  -lmlx  -framework AppKit -framework OpenGL -O3

DEPND =  src/init.c src/pars.c src/maps.c src/window.c fractol.c src/events.c src/drawing.c

all : $(NAME)

$(NAME) : $(DEPND)
	cc  $(CFLAGS) $(MLXFLGS) $(DEPND) -o $(NAME)
clean :
	rm -rf fractol
re : clean all