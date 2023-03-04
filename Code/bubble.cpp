#include <iostream>
using namespace std;
void sort (int* p, int n)
{
    int c=0;
    for (;;)
    {
        int a=1;
        for (int i=0; i<n-c-1; i++)
        {
            if (p[i]>p[i+1])
            {
                int d=p[i];
                p[i]=p[i+1];
                p[i+1]=d;
                a=0;
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
    int p[10000];
    cin>>n;
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
