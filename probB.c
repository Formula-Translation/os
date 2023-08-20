#include <stdio.h>
#include <stdlib.h>

int globalA;
char globalB;
int globalC = 1000;

int Plus(int n)
{
    if (n >= globalC)
    {
        return n;
    }
    n += 100;
    printf("Address of n in Plus : %p\n", &n);
    return Plus(n);
}

int CustomMalloc(int n) 
{
    if (n == 0)
    {
        return 1;
    }
    int *mallocC = (int *)malloc(10 * sizeof(int));
    printf("Address of  malloc C : %p\n", &mallocC[0]);
    return CustomMalloc(n - 1);
}

int main()
{
    int localA = 10; //stack
    int localB = 20; //stack
    int localC = 30; //stack
    printf("Address of local variable A : %p\n", (void *)&localA);
    printf("Address of local variable B : %p\n", (void *)&localB);

    Plus(localB);

    int *mallocA = (int *)malloc(10 * sizeof(int)); //heap
    int *mallocB = (int *)malloc(10 * sizeof(int)); //heap

    for (int i = 0; i < 10; i++)
    {
        printf("Address of  malloc A [%d] : %p\n", i + 1, (void *)&mallocA[i]);
    }   

    CustomMalloc(localA);
    free(mallocA);
    free(mallocB);

    printf("Address of global variable A : %p\n", (void *)&globalA); //Unitialized data
    printf("Address of global variable B : %p\n", (void *)&globalB); //Unitialized data
    printf("Address of global variable C: %p\n", (void *)&globalC); //initialized data
    return 0;
}

// n decrease malloc C, malloc A increase
