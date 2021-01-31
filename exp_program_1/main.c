#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int some_local = 3;
    int some_other = 7;
    int something;
    something = some_other + some_local;
    
    for (int i = 0; i < 10; i++){
        printf("i: %d\n", i);
        some_local++;
    }
    
    printf("Some %d + %d = %d, if you see this printing that's good\n", some_local, some_other, something);
    printf("\nTry placing placing a breakpoint by holding your mouse over the left\n");
    printf("side of a line number in main.c and clicking on the red dot that shows up\n");
    printf("\nAfter placing the breakpoint try running the debugger with the `f5` key\n");

    return 0;
}
