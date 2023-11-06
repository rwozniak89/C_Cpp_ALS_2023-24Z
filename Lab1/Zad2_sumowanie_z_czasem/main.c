#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long sumValuesU (unsigned long long n)
{
    clock_t start=clock();
    unsigned long long res=0;
    for(unsigned long long i=1;i<=n;i++)
    {
        res+=(i*(i+1))/2;
    }
    clock_t stop=clock()-start;
    double time_in_seconds = (double)stop/(double)CLOCKS_PER_SEC;
    printf("n: %llu, result: %llu, time: %f seconds\n", n, res, time_in_seconds);
    return res;
}

unsigned long long sumValuesU2 (unsigned long long n)
{
    clock_t start=clock();
    unsigned long long res=0;
    for(unsigned long long i=1;i<=n;i++)
    {
        for(unsigned long long j=1;j<=i;j++)
        {
            res+=j;
        }
    }
    clock_t stop=clock()-start;
    double time_in_seconds = (double)stop/(double)CLOCKS_PER_SEC;
    printf("n: %llu, result: %llu, time: %f seconds\n", n, res, time_in_seconds);
    return res;
}


int main()
{
    printf("Zad2 sumowanie z pomiarem czasu!\n");

    sumValuesU(1000);
    sumValuesU(10000);
    sumValuesU(100000);
    sumValuesU(150000);
    sumValuesU(100000);
    sumValuesU(1000000);
    sumValuesU(10000000);
    sumValuesU(100000000);

    sumValuesU2(1000);
    sumValuesU2(10000);
    sumValuesU2(100000);
    sumValuesU2(150000);
    sumValuesU2(200000);
    //sumValuesU2(250000);
    //sumValuesU2(1000000);
    //sumValuesU2(10000000);



    return 0;
}
