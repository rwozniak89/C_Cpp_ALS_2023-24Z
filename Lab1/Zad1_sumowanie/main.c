#include <stdio.h>
#include <stdlib.h>
//przyklaad z pust¹ petl¹ dla pokazania zlozonosci, ale to nie jest prawidlowe rozwi¹zanie!
void sumValuesC(int n){
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
    printf("n: %i, result: %i, counter: %i\n", n, sum, counter);
}

void sumValuesB(int n){
    int sum = 0;
    int counter=2;
    for(int i=1; i <= n; i++)
    {
        sum += i;
        counter+=2;
    }
    printf("n: %i, result: %i, counter: %i\n", n, sum, counter);
}

void sumValuesA(int n){
    int counter=1;
    int sum = (n*(n+1)/2);
    printf("n: %i, result: %i, counter: %i\n", n, sum, counter);
}




int main()
{
    printf("Zad1_sumowanie\n");

    sumValuesA(10);
    sumValuesA(100);
    sumValuesA(1000);

    sumValuesB(10);
    sumValuesB(100);
    sumValuesB(1000);

    sumValuesC(10);
    sumValuesC(100);
    sumValuesC(1000);

    return 0;
}





