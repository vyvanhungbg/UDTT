#include<iostream>
using namespace std;
void view_config(int a[], int k)
{
    for(int i=1;i<=k;i++)
        cout<<a[i];
    cout<<endl;
}
void next_config(int a[], int k, int i)
{
    a[i] = a[i]+1;
    i++;
    while(i<=k)
    {
        a[i] = a[i-1]+1;
        i++;
    }
}
void listing_config(int n, int k)
{
    int a[k+1];
    for(int i=1;i<=k;i++)
        a[i] = i;
    int i;
    do
    {
        view_config(a,k);
        i = k;
        while(i>0 && a[i] == n-k+i)
            i--;
        if(i>0)
            next_config(a,k,i);
    }while(i>0);
}
int main()
{
    listing_config(6,5);
    return 0;
}
