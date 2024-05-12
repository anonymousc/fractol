# Mandelbrot Set Visualization using MLX

## Introduction
This project aims to visualize the famous Mandelbrot set using the MLX library in C. The Mandelbrot set is a set of complex numbers for which the function \( f_c(z) = z^2 + c \) does not diverge when iterated from \( z = 0 \), i.e., the sequence \( f_c(0), f_c(f_c(0)), f_c(f_c(f_c(0))), \ldots \) remains bounded.

## About Mandelbrot Set Is the Main one
The Mandelbrot set is named after the mathematician Benoît B. Mandelbrot, who studied it in the 1970s and 1980s. It is perhaps the most famous example of a fractal - a mathematical object that displays self-similar patterns at every scale.

## About MLX
MLX is a simple graphics library in C primarily used for creating graphical user interfaces in UNIX-based systems. It provides basic functionalities for rendering graphics, such as drawing points, lines, and shapes on the screen.

## Getting Started
To run the Mandelbrot set visualization:

1. Make sure you have MLX installed on your system.
2. Clone this repository.
3. Compile the code using the provided Makefile.
4. Run the executable.

## Usage
The program allows you to navigate and zoom into different regions of the Mandelbrot set using mouse clicks and keyboard inputs.

- Use arrow keys to move the viewport.
- Use mouse scroll to zoom in/out.
- Press 'ESC' to exit the program.

## Dependencies
- MLX library
- Z suit for the formula (Zn+1 = Z^2 + c)
- 42 docs

## References
- [Wikipedia - Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [MLX Documentation](https://harm-smits.github.io/42docs/libs/minilibx.html)

## License
This project is licensed under the [42 coding school](42.fr).
