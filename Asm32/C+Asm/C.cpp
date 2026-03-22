
#include <stdio.h>

extern "C" int SubFunc (int a, int b);

int main()
    {
    printf ("\n" ">>> main(): start\n\n");

    int a = 10, b = 15;
    
    int c = SubFunc (a, b);

    printf ("main():    %d - %d = %d\n", a, b, c);

    printf ("\n" "<<< main(): end\n\n");
    return 0;
    }
