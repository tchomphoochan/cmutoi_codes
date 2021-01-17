#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int arr[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                for (int j = 0; j < 5; j++)
                {
                    printf("%d", arr[j]);
                    if (j != 4)
                        printf(" ");
                    else
                        printf("\n");
                }
                swapped = true;
            }
        }
    }

    return 0;
}