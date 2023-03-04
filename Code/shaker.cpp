#include <iostream>
using namespace std;
void sort (int* p, int n)
{
    int c=0;
    for (;;)
    {
        int a=1;
        int c1=(c-c%2)/2;
        int c2=(c+c%2)/2;
        for (int i=c1; i<n-c2-1; i++)
        {
            int i0;
            if (c2>c1)
            {
                i0=n-c2-1+c1-i;
                if (p[i0]<p[i0-1])
                {
                    int d=p[i0];
                    p[i0]=p[i0-1];
                    p[i0-1]=d;
                    a=0;
                }
            }
            else
            {
                i0=i;
                if (p[i0]>p[i0+1])
                {
                    int d=p[i0];
                    p[i0]=p[i0+1];
                    p[i0+1]=d;
                    a=0;
                }
            }
        }
        if (a==1)
        {
            break;
        }
        else
        {
            c++;
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
