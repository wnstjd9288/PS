#include <stdio.h>

int main()
{
    int a[8];
    int state=0;
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
        if(i!=0&&a[i-1]+1==a[i])state++;
        if(i!=0&&a[i-1]-1==a[i])state--;
    }
    if(state==7) printf("ascending");
    else if(state==-7) printf("descending");
    else printf("mixed");
    return 0;
}