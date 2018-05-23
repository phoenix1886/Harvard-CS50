#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    } while (height <0 || height > 23);
    for (int i=0; i < height; i++)
    {
        int num_of_spaces = height - 1 - i;
        int num_of_hashes = height + 1 - num_of_spaces;
        for (int j = 0; j < num_of_spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < num_of_hashes; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}