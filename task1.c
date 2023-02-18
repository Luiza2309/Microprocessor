#include<stdio.h>

void conversia(unsigned int v[], unsigned int x)
{
    
    for(int i=31; i>=0; i--)
    {
        if(((1 << i) & x) != 0)
            v[31-i]=1;
        else
            v[31-i]=0;
    }
}

int main()
{
    unsigned int x, N, Dim;
    unsigned int v[32]={0};
    //x este numarul dat
    //v este vectorul care memoreaza bitii numarului dat

    scanf("%d", &x);
    conversia(v, x);

    N=v[0]*4+v[1]*2+v[2]+1;
    printf("%d ", N);

    for(int i=3; i<=(N*2+2); i=i+2)
    {
        if(v[i]==0 && v[i+1]==0)
            printf("+ ");
        if(v[i]==0 && v[i+1]==1)
            printf("- ");
        if(v[i]==1 && v[i+1]==0)
            printf("* ");
        if(v[i]==1 && v[i+1]==1)
            printf("/ ");
    }

    Dim=v[2*N+3]*8+v[2*N+4]*4+v[2*N+5]*2+v[2*N+6]+1;
    printf("%d\n", Dim);

    return 0;
}