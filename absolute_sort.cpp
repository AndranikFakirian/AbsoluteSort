#include <iostream>
using namespace std;
class Array
{
public:
    Array(unsigned long int size);
    ~Array();
    void arrWrite();
    void arrPrint();
    void bubbleSort();
    void choiserSort();
    void shakerSort();
    void combSort();
    void heapSort();
    void quickSort(unsigned long int m, unsigned long int n);
private:
    int *arr;
    unsigned long int arrSize;
};
Array::Array(unsigned long int size)
{
    arrSize=size;
    arr=new int[arrSize];
}
Array::~Array()
{
    delete [] arr;
}
void Array::arrWrite()
{
    for (unsigned long int i=0; i<arrSize; i++)
    {
        int a;
        cin>>a;
        arr[i]=a;
    }
}
void Array::arrPrint()
{
    for (unsigned long int i=0; i<arrSize; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void Array::bubbleSort()
{
    unsigned long int c=0;
    for (;;)
    {
        int a=1;
        for (unsigned long int i=0; i<arrSize-c-1; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int d=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=d;
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
void Array::choiserSort()
{
    unsigned long int n=arrSize;
    int *m=new int[n];
    for (unsigned long int i=0; i<n; i++)
    {
        int *q=new int[n-1-i];
        int mi=99999;
        int jmi;
        for (unsigned long int j=0; j<n-i; j++)
        {
            if (arr[j]<mi)
            {
                mi=arr[j];
                jmi=j;
            }
        }
        m[i]=mi;
        int a=0;
        for (unsigned long int j=0; j<n-i-1; j++)
        {
            if (j==jmi)
            {
                a=1;
            }
            q[j]=arr[j+a];
        }
        int *del=arr;
        arr=q;
        delete [] del;
    }
    int *del=arr;
    arr=m;
    delete [] del;
}
void Array::shakerSort()
{
    unsigned long int c=0;
    for (;;)
    {
        int a=1;
        unsigned long int c1=(c-c%2)/2;
        unsigned long int c2=(c+c%2)/2;
        for (unsigned long int i=c1; i<arrSize-c2-1; i++)
        {
            unsigned long int i0;
            if (c2>c1)
            {
                i0=arrSize-c2-1+c1-i;
                if (arr[i0]<arr[i0-1])
                {
                    int d=arr[i0];
                    arr[i0]=arr[i0-1];
                    arr[i0-1]=d;
                    a=0;
                }
            }
            else
            {
                i0=i;
                if (arr[i0]>arr[i0+1])
                {
                    int d=arr[i0];
                    arr[i0]=arr[i0+1];
                    arr[i0+1]=d;
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
void Array::combSort()
{
    unsigned long int n=arrSize;
    for (;n>0;)
    {
        float n1=n/1.3;
        n=(unsigned long int)n1;
        for (unsigned long int i=0; i<arrSize-n; i++)
        {
            if (arr[i]>arr[i+n])
            {
                int d=arr[i];
                arr[i]=arr[i+n];
                arr[i+n]=d;
            }
        }
    }
}
void Array::heapSort()
{
    unsigned long int n=arrSize;
    for (unsigned long int a=0; a<n-1; a++)
    {
        for (unsigned long int i=n-1-a; i>0;i-=2)
        {
            unsigned long int i0=(i+i%2)/2-1;
            unsigned long int i2;
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
                unsigned long int mai;
                if (arr[i]>arr[i2])
                {
                    ma=arr[i];
                    mai=i;
                }
                else
                {
                    ma=arr[i2];
                    unsigned long mai=i2;
                }
                if (arr[i0]<ma)
                {
                    arr[mai]=arr[i0];
                    arr[i0]=ma;
                }
            }
            else
            {
                int ma=arr[i];
                if (arr[i0]<ma)
                {
                    arr[i]=arr[i0];
                    arr[i0]=ma;
                }
            }
        }
        int c=arr[0];
        arr[0]=arr[n-a-1];
        arr[n-a-1]=c;
    }
}
void Array::quickSort(unsigned long int m, unsigned long int n)
{
    if (n!=m)
    {
        int c=(m+n+(m+n)%2)/2;
        int a=0;
        int b=0;
        for (int i=m; i+b<n+m-i-a; i++)
        {
            if (arr[i+b]<arr[c])
            {
                b++;
                i--;
                continue;
            }
            else if (arr[n+m-i-a]>arr[c])
            {
                a++;
                i--;
                continue;
            }
            else
            {
                if (i+b==c)
                {
                    int d=arr[n+m-i-a];
                    arr[n+m-i-a]=arr[c];
                    arr[c]=d;
                    c=n+m-i-a;
                    i--;
                    continue;
                }
                else if (n+m-i-a==c)
                {
                    int d=arr[i+b];
                    arr[i+b]=arr[c];
                    arr[c]=d;
                    c=i+b;
                    i--;
                    continue;
                }
                else
                {
                    int d=arr[n+m-i-a];
                    arr[n+m-i-a]=arr[i+b];
                    arr[i+b]=d;
                }
            }
        }
        if (n-m!=1)
        {
            quickSort(m, c);
            quickSort(c, n);
        }
    }
}
int main ()
{
    unsigned long int n;
    cin>>n;
    Array p(n);
    p.arrWrite();
    char c;
    cout<<"Which sort?"<<endl;
    cin>>c;
    switch (c)
    {
        case 'b':
            p.bubbleSort();
            break;
        case 'c':
            cout<<"So?"<<endl;
            cin>>c;
            switch (c)
            {
                case 'h':
                    p.choiserSort();
                    break;
                case 'o':
                    p.combSort();
                    break;
            }
            break;
        case 'h':
            cout<<"Doesn\'t work"<<endl;
            //p.heapSort();
            break;
        case 'q':
            p.quickSort(0, n-1);
            break;
        case 's':
            p.shakerSort();
            break;
    }
    p.arrPrint();

    return 0;
}
