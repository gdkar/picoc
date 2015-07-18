#include "stdio.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))

void main()
{
    double x = MIN(1,2);
    int y = 14;
    double z;
    z = MIN(y, 13.5);
    y = MIN(y, 13);
    
    double pi = 3.14;
    int pi_int = pi;
    
    printf("Macro test: %d %d %f %d \n", x, y, z, pi_int);
}
