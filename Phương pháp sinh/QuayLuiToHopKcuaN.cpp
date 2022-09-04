#include<iostream>
using namespace std;
int n=7;
int k=5;
int a[5];
int dd[5];
void show()
{
    for(int i=1;i<=k;i++)
        cout<<a[i];
    cout<<endl;
}
void Try( int i)
{
    for(int j=1;j<=n-k+i;j++)
    {
        if(dd[j] == 0)
        {
            a[i] = j;
            if(i==k)
                show();
            else
            {
                dd[j] = 1;
                Try( i+1);
                dd[j] =0;
            }
        }
    }
}
int main()
{
    Try(1);
    return 0;
}
