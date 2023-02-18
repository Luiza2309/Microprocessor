#include<stdio.h>
#include<math.h>

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

void convertirea_unsigned_short(unsigned short v[], unsigned short x)
{
    
    for(int i=15; i>=0; i--)
    {
        if(((1 << i) & x) != 0)
            v[15-i]=1;
        else
            v[15-i]=0;
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
    Dim=v[2*N+3]*8+v[2*N+4]*4+v[2*N+5]*2+v[2*N+6]+1;

    unsigned short cate_nr;

    if(((N+1)*Dim)%16==0)
        cate_nr=((N+1)*Dim)/16;
    else
        cate_nr=((N+1)*Dim)/16+1;
    
    unsigned short nr_introdus, m=0;
    //m este numarul operanzilor
    unsigned short w[16]={0}, operanzi[16]={0};
    //w memoreaza bitii numerelor introduse de la tastatura
    unsigned s[1000];
    unsigned s_contor=0;
    //s memoreaza toti bitii tuturor numerelor luate de la tastatura

    for(int i=0; i<cate_nr; i++)
    {
        //for care parcurge numerele luate de la tastatura
        scanf("%hd", &nr_introdus);
        convertirea_unsigned_short(w, nr_introdus);

        for(int i=0; i<16; i++)
            s[s_contor++]=w[i];
        //adaugarea la finalul vectorului elementele din w
    }
        
    for(int j=0; j<s_contor; j=j+Dim)
    {
        //for care parcurge "bucatile" numerelor luate de la tastatura
        int putere=0;
        for(int k=j+Dim-1; k>=j; k--)
        {
            operanzi[m]+=s[k]*pow(2, putere);
            putere++;
        }
        //parcurge bitii din fiecare bucata si le transforma in baza 10
        m++;
    }
    
    int rezultat=operanzi[0], oper=1;
    //oper retine contorul numarului care urmeaza a fi introdus in operatie
    for(int i=3; i<=(N*2+2); i=i+2)
    {
        if(v[i]==0 && v[i+1]==0)
        {
            rezultat+=operanzi[oper];
            oper++;
        }
        if(v[i]==0 && v[i+1]==1)
        {
            rezultat-=operanzi[oper];
            oper++;
        }
        if(v[i]==1 && v[i+1]==0)
        {
            rezultat*=operanzi[oper];
            oper++;
        }
        if(v[i]==1 && v[i+1]==1)
        {
            rezultat/=operanzi[oper];
            oper++;
        }
    }
    printf("%d\n", rezultat);
    return 0;
}