#include <stdio.h>
#include <cs50.h>

void card_verifier(long card_number);
int digit_counter(long card_number);

int main(void) // Might not be int, because we're returning a string
{
    long card_number;

    do
    {
        card_number = get_long("Card Number:");
    } while (digit_counter(card_number) < 13 || digit_counter(card_number) > 16);

    card_verifier(card_number);
}


int digit_counter(long card_number)
{
    int counter = 0;
    long temp = card_number;
    while (temp > 0)
    {
        temp = temp / 10;
        counter++;
    }
    return counter;
}


void card_verifier(long card_number)
{
    long temp = card_number;
    int remaining_length = digit_counter(card_number);
    int counter = 1;
    int check = 0;
    int first_two_digits;
    int first_digit;
    int digit_count = digit_counter(card_number);

    for (; remaining_length > 0; remaining_length--)
    {
        if (remaining_length == 2) {
            first_two_digits = temp;
        }
        if (remaining_length == 1) {
            first_digit = temp;
        }
        if (counter % 2 == 1)
        {
            int digit = temp % 10;
            check += digit;
            temp = temp / 10;
            counter++;
        } else {
            int digit = temp % 10;
            int product = digit * 2;
            check += (product % 10) + (product / 10);
            temp = temp / 10;
            counter++;
        }
    }
    check = check % 10;
    printf("%d\n", check);
    if (check != 0) {
        printf("INVALID\n");
    } else {
        if (digit_count == 15 && (first_two_digits == 34 || first_two_digits == 37)) {
            printf("AMEX\n");
        }
        if ((first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55) && digit_count == 16) {
            printf("MASTERCARD\n");
        }
        if ((digit_count == 13 || digit_count == 16) && first_digit == 4) {
            printf("VISA\n");
        }
    }
}