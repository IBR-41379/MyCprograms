#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,n1;
    scanf("%d", &n);
    for(int i=0;i<n+(n-1);i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            n1=i < j ? i : j;
            n1=n1 < 2*n-1-i ? n1 : 2*n-1-i-1;
            n1=n1 < 2*n-1-j-1 ? n1 : 2*n-1-j-1;
            printf("%d ", n-n1);
        }
        printf("\n");
    }
      // Complete the code to print the pattern.
    return 0;
}
