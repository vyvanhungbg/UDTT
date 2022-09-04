#include<iostream>
using namespace std;
int a[5];
int n=5;
void show()
{
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
}
void Try(int k)
{
    for(int i=0;i<=1;i++)
    {
        a[k] = i;
        if(n==k)
            show();
        else
            Try(k+1);
    }
}
int main()
{
    Try(0);
    return 0;
}
