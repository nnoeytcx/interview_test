#include <stdio.h>

// 0 + 1 -> 1
// 1 + 1 -> 2
// 1 + 2 -> 3
// 0 1 1 2 3 5 8 13 21 ...... x .......

int findPlace(int n)
{
    int k = 2, f1=0, f2=1,temp=0;
    if (n == 0)
        printf("1\n");
    else
    {
        while(f2 < n)
        {
            temp=f1;
            f1=f2;
            f2+=temp;
            // printf("%d->", f2);
            k++;
        }
        printf("%d\n",k);
    }
}

int main()
{
    findPlace(0);
    findPlace(1);
    findPlace(2);
    findPlace(5);
    findPlace(8);
    findPlace(21);
    return 0;
}