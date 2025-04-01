#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
    int i=1;
    double vt[N];
    double *p_vt = vt;

    srand(time(NULL));
    while (p_vt<vt+N)
    {
        *p_vt = 1+rand()%100;
        printf("%d [%.2f]  \n",i ,*p_vt);
        p_vt++;
        i++;
    }

    return 0;
} 