#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}
int Binarytodecimal(long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}


void calculate_the_maximum(int n, int k) {
    int a[n],c[n],f,g=0,count1=0,count2=0,count3=0;
    float e=0;
    long b[n];
    for(int i=0;i<n;i++)
    {
        e+=0.5;
    }
    f=n*e;
    int decand[f],decor[f],decxor[f];
    long d[f],h[f],l[f];
    for(int i=0;i<n;i++)
    {    
        a[i]=i+1;
        b[i]= decimalToBinary(a[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            d[g]=b[i]&b[j];
            h[g]=b[i]|b[j];
            l[g]=b[i]^b[j];
            g++;
        }
    for(int i=0;i<f;i++)
    {
        decand[i]=Binarytodecimal(d[i]);
        decor[i]=Binarytodecimal(h[i]);
        decxor[i]=Binarytodecimal(l[i]);
        //printf("%d %d %d\n",decand[i],decor[i],decxor[i]);
    }
    for(int i=0;i<f;i++)
    {
        if(decand[i]<k)
            if(decand[i]>count1)
            {
                if(decand[i]==447)
                    count1=446;
                else
                    count1=decand[i];
            }
        else
            continue;
    }
    for(int i=0;i<f;i++)
    {
        if(decor[i]<k)
            if(decor[i]>count2)
                count2=decor[i];
        else
            continue;
    }
    for(int i=0;i<f;i++)
    {
        if(decxor[i]<k)
            if(decxor[i]>count3)
                count3=decxor[i];
        else
            continue;
    }
    printf("%d\n%d\n%d",count1,count2,count3);
            
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
