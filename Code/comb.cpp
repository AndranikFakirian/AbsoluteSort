#include <iostream>
using namespace std;
void sort (int* p, int n)
{
    int n0=n;
    for (;n0>0;)
    {
        float n01=n0/1.3;
        n0=int(n01);
        for (int i=0; i<n-n0; i++)
        {
            if (p[i]>p[i+n0])
            {
                int d=p[i];
                p[i]=p[i+n0];
                p[i+n0]=d;
            }
        }
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
    sort(p, n);
    for (int i=0; i<n; i++)
    {
        cout<<p[i]<<' ';
    }

    return 0;
}
