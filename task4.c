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

    int rezultat=0, oper=0, aux=2*N+2;
    //oper retine contorul numarului care urmeaza a fi introdus in operatie
    //aux este indicele la care se termina operatiile in vector
    int i=3;
    while(i<=aux)
    {
        if(v[i]==1 && v[i+1]==0)
        {
            operanzi[oper]=operanzi[oper]*operanzi[oper+1];
            //salveaza inmultirea in primul operand
            for(int j=oper+1; j<m; j++)
                operanzi[j]=operanzi[j+1]; 
            m--; //sterge al doilea operand
            for(int k=i; k<aux; k++)
                v[k]=v[k+2]; 
            aux=aux-2; //sterge operatia efectuata
            oper--; //ramane la operandul care a salvat inmultirea
            i-=2; //s-au dat toate operatiile in spate; ramane la aceeasi oper
        }
        if(v[i]==1 && v[i+1]==0)
        {
            operanzi[oper]=operanzi[oper]/operanzi[oper+1];
            for(int j=oper+1; j<m; j++)
                operanzi[j]=operanzi[j+1];
            m--;
            for(int k=i; k<aux; k++)
                v[k]=v[k+2];
            aux=aux-2;
            oper--;
            i-=2;
        }
        oper++; 
        i+=2; //daca n-a gasit o operatie de gradul 2, trece mai departe
    }
    
    rezultat=operanzi[0];
    oper=1;
    for(int i=3; i<=aux; i=i+2)
    {
        if(v[i]==0 && v[i+1]==0)
        {
            rezultat=rezultat+operanzi[oper];
            oper++;
        }
        if(v[i]==0 && v[i+1]==1)
        {
            rezultat=rezultat-operanzi[oper];
            oper++;
        }

    }
    printf("%d\n", rezultat);
    return 0;
}