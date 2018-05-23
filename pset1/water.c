#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int bottles_per_min = 12;
    printf("Minutes: ");
    int minutes = get_int();
    printf("Bottles: %d\n", minutes * bottles_per_min);

    return 0;
}