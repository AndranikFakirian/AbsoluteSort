#include <iostream>
using namespace std;
void sort (int* p, int n)
{
    int q[10000];
    int m[10000];
    for (int i=0; i<n; i++)
    {
        int mi=99999;
        int jmi;
        for (int j=0; j<n-i; j++)
        {
            if (p[j]<mi)
            {
                mi=p[j];
                jmi=j;
            }
        }
        m[i]=mi;
        int a=0;
        for (int j=0; j<n-i-1; j++)
        {
            if (j==jmi)
            {
                a=1;
            }
            q[j]=p[j+a];
        }
        for (int j=0; j<n-i-1; j++)
        {
            p[j]=q[j];
        }
    }
    for (int i=0; i<n; i++)
    {
        p[i]=m[i];
    }
}
int main ()
{
    int n;
    cin>>n;
    int p[10000];
    for (int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    sort (p, n);
    for (int i=0; i<n; i++)
    {
        cout<<p[i]<<' ';
    }

    return 0;
}
