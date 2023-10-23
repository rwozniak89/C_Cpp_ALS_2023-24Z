#include <stdio.h>
#include <stdlib.h>

void sumValues(int n){
    int sum = 0;
    //int n = 10;
    int counter=2;

    counter+=1;
    for(int i=1; i <= n; i++)
    {
        sum += i;
        counter+=2;
    }

    printf("n: %i\n", n);
    printf("result: %i\n", sum);
    printf("counter: %i\n\n", counter);
}

//przyklaad z pust¹ petl¹ dla pokazania zlozonosci, ale to nie jest prawidlowe rozwi¹zanie!
void sumValues2(int n){
    int sum = 0;
    //int n = 10;
    int counter=2;

    counter+=1;
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j <= n; j++)
        {
            counter+=1;
        }
        sum += i;
        counter+=2;
    }

    printf("n: %i\n", n);
    printf("result: %i\n", sum);
    printf("counter: %i\n\n", counter);
}

void sumValues2v2(int n);


int main()
{
    printf("Zad1_sumowanie\n");

    sumValues(10);
    sumValues(100);
    sumValues(1000);

    sumValues2(10);
    sumValues2(100);
    sumValues2(1000);

    return 0;
}





