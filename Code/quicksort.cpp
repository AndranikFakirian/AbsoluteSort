#include <iostream>
using namespace std;
void sort (int* p, int m, int n)
{
    if (n!=m)
    {
        int c=(m+n+(m+n)%2)/2;
        int a=0;
        int b=0;
        for (int i=m; i+b<n+m-i-a; i++)
        {
            if (p[i+b]<p[c])
            {
                b++;
                i--;
                continue;
            }
            else if (p[n+m-i-a]>p[c])
            {
                a++;
                i--;
                continue;
            }
            else
            {
                if (i+b==c)
                {
                    int d=p[n+m-i-a];
                    p[n+m-i-a]=p[c];
                    p[c]=d;
                    c=n+m-i-a;
                    i--;
                    continue;
                }
                else if (n+m-i-a==c)
                {
                    int d=p[i+b];
                    p[i+b]=p[c];
                    p[c]=d;
                    c=i+b;
                    i--;
                    continue;
                }
                else
                {
                    int d=p[n+m-i-a];
                    p[n+m-i-a]=p[i+b];
                    p[i+b]=d;
                }
            }
        }
        if (n-m!=1)
        {
            sort(p, m, c);
            sort(p, c, n);
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
    sort(p, 0, n-1);
    for (int i=0; i<n; i++)
    {
        cout<<p[i]<<' ';
    }

    return 0;
}
