#include <stdio.h>
#include <cs50.h>

int coin_count(int change);

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed:\n");
    }
    while(change < 0);
   
    printf("%d\n", coin_count(change));
}

int coin_count(int change)
{
    int coins = change / 25;
    change = change % 25;

    coins += change / 10;
    change = change % 10;

    coins += change / 5;
    change = change % 5;

    coins += change / 1;
    change = change % 1;

    return coins;
}