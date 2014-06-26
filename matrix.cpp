#include<iostream>
using namespace std;

const int N=7;

int MatrixChainOrder2(int *p,int m[N][N],int s[N][N],int i, int j)
{
    
    if (i == j)
    {
        return 0;
    }
    if (m[i][j] < 0x7fffffff)
    {
        return m[i][j];
    }

    for (int k=i; k<j; ++k)
    {
        
        int tmp = MatrixChainOrder2(p,m,s,i,k) + MatrixChainOrder2(p,m,s,k+1,j) + p[i-1]*p[k]*p[j];
        if (tmp < m[i][j])
        {
            m[i][j] = tmp;
            s[i][j] = k;
        }
    }
    return m[i][j];
}


void PrintAnswer(int s[N][N],int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j]+1,j);
        cout<<")";
    }
}


int main()
{
    int p[N]={30,35,15,5,10,20,25};
    int m[N][N],s[N][N];

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            m[i][j] = 0x7fffffff;
    }
    cout << MatrixChainOrder2(p,m,s,1,6)<<endl;
    PrintAnswer(s,1,N-1);
    return 0;
}