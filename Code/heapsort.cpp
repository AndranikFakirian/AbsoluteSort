#include <iostream>
using namespace std;
void sort (int* p, int n)
{
    for (int a=0; a<n-1; a++)
    {
        for (int i=n-1-a; i>0;i-=2)
        {
            int i0=(i+i%2)/2-1;
            int i2;
            if (i%2==0)
            {
                i2=i-1;
            }
            else if (i<n-1-a)
            {
                i2=i+1;
            }
            else
            {
                i2=-1;
            }
            if (i2!=-1)
            {
                int ma;
                int mai;
                if (p[i]>p[i2])
                {
                    ma=p[i];
                    mai=i;
                }
                else
                {
                    ma=p[i2];
                    mai=i2;
                }
                if (p[i0]<ma)
                {
                    p[mai]=p[i0];
                    p[i0]=ma;
                }
            }
            else
            {
                int ma=p[i];
                if (p[i0]<ma)
                {
                    p[i]=p[i0];
                    p[i0]=ma;
                }
            }
        }
        int c=p[0];
        p[0]=p[n-a-1];
        p[n-a-1]=c;
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
