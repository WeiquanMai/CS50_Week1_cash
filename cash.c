#include <cs50.h>
#include <stdio.h>

int get_change_owed();
int min_coins(int change);

int main(void)
{
    int change = get_change_owed();
    int num_coins = min_coins(change);
    printf("%i\n", num_coins);
}

// Get change owed and repeatedly prompt user until they enter a valid number
int get_change_owed()
{
    int change;

    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    return change;
}

// Calculate minimum number of coins owed using quarters, dimes, nickles, and pennies
int min_coins(int change)
{
    // variables
    int counter = 0;
    int quarter = 25;
    int dime = 10;
    int nickle = 5;
    int penny = 1;

    // While change is above 0 repeatedly loop through to see if change is greater than quarter, dime, nickle, or penny and subtract the biggest piece out.
    while (change > 0)
    {
        if (change - quarter >= 0)
        {
            change -= quarter;
            counter++;
        }
        else if (change - dime >= 0)
        {
            change -= dime;
            counter++;
        }
        else if (change - nickle >= 0)
        {
            change -= nickle;
            counter++;
        }
        else if (change - penny >= 0)
        {
            change -= penny;
            counter++;
        }
    }

    return counter;
}
