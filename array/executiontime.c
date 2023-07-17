#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int  main()
{

    int i;
    clock_t t;
    t=clock();
    print("Hello World\n");
    for(i=0;i<1000;i++)
    {

    }
    t=clock()-t;
    double time_taken=((double)t);

    printf("took %f milliseconds to execute\n",time_taken);
    return 0;
}

