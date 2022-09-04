#include<iostream>
using namespace std;
void view_config(int a[], int k)
{
    for(int i=1;i<=k;i++)
        cout<<a[i];
    cout<<endl;
}
void next_config(int a[], int n, int i)
{
    int k=n;
    while(k>0 && a[k] <a[i])
        k--;
    swap(a[k], a[i]);
    i++;
    int j=n;
    while(i<j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
void listing_config(int n)
{
    int a[n+1];
    for(int i=1;i<=n;i++)
        a[i] =i;
    int i;
    do
    {
        view_config(a,n);
        i = n-1;
        while(i>0 && a[i] > a[i+1])
            i--;
        if(i>0)
            next_config(a,n,i);
    }while(i>0);
}
int main()
{
    listing_config(5);
    return 0;
}

