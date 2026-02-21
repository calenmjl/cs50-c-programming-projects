#include <stdio.h>
#include <cs50.h>

void print_row(int row, int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("How high must Mario climb?\n");
    } while (height < 1 || height > 8);
    for (int row = 1; row <= height; row++)
    {
        print_row(row, height);
        printf("\n");
    }
}

void print_row(int row, int height)
{
    for (int i = 0; i < (height - row); i++)
    {
        printf(" ");
    }
    for (int j = 0; j < row; j++)
    {
        printf("#");
    }
    
    printf("  ");

        for (int j = 0; j < row; j++)
    {
        printf("#");
    }
}