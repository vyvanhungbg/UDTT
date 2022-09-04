#include<iostream>
using namespace std;
void view_config(int a[], int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
}
void next_config(int a[], int n, int i)
{
    a[i] =1;
    i++;
    while(i<=n)
    {
        a[i] =0;
        i++;
    }
}
void listing_config(int n)
{
    int a[n+1];
    for(int i=1;i<=n;i++)
        a[i] = 0;
    int i;
    do
    {
        view_config(a,n);
        i = n;
        while(i>0 && a[i] == 1)
            i--;
        if(i>0)
            next_config(a,n,i);
    }while(i>0);
}
int main()
{
    listing_config(3);
    return 0;
}
