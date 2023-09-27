#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    int i = 0;
    double real = x;
    double imag = y;

    while (i < MAX_ITER) {
        double real2 = real * real;
        double imag2 = imag * imag;
        if (real2 + imag2 > 4.0)
            break;
        imag = 2 * real * imag + y;
        real = real2 - imag2 + x;
        i++;
    }

    return i;
}

int main() {
    void *mlx;
    void *win;
    int x = 0;
    int y = 0;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");

    while (x < WIDTH) {
        y = 0;
        while (y < HEIGHT) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int color = mandelbrot(real, imag);
            mlx_pixel_put(mlx, win, x, y, color);
            y++;
        }
        x++;
    }

    mlx_loop(mlx);
    return 0;
}
