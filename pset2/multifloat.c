#include <stdio.h>
#include <stdlib.h>

double multiply_float(double x, double y);

int main(int argc, char *argv[])
{
    if(argc == 3)
    {
        double x = strtod(argv[1], NULL);
        double y = strtod(argv[2], NULL);
        printf("%f\n", multiply_float(x, y));
    }
    else
    {
        printf("You're retarded.  Try 2 numbers.\n");
    }


}

double multiply_float(double x, double y)
{
    return x * y;
}