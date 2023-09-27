#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

#define JULIA_REAL -0.7
#define JULIA_IMAG 0.27015

int julia(double x, double y)
{
    int i = 0;
    double real = x;
    double imag = y;

    while (i < MAX_ITER)
    {
        double real2 = real * real;
        double imag2 = imag * imag;
        if (real2 + imag2 > 4.0)
            break;
        imag = 2 * real * imag + JULIA_IMAG;
        real = real2 - imag2 + JULIA_REAL;
        i++;
    }

    return (i);
}

int mandelbrot(double x, double y)
{
    int i = 0;
    double real = x;
    double imag = y;

    while (i < MAX_ITER)
    {
        double real2 = real * real;
        double imag2 = imag * imag;
        if (real2 + imag2 > 4.0)
            return i;
        imag = 2 * real * imag + y;
        real = real2 - imag2 + x;
        i++;
    }

    return (MAX_ITER);
}

int main()
{
    void *mlx;
    void *win;
    int x = 0;
    int y = 0;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");

    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int color = mandelbrot(real, imag);
            mlx_pixel_put(mlx, win, x, y, color * 0x00010101); // Color mapping
            x++;
        }
        y++;
    }
    
    mlx_loop(mlx);
    return (0);
}
