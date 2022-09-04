#include<iostream>
using namespace std;
int n=5;
int a[5];
int dd[5];
void show()
{
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
}
void Try(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(dd[i] == 0)
        {
            a[k] = i;
            if(k == n)
                show();
            else
            {
                dd[i] =1;
                Try(k+1);
                dd[i] = 0;
            }
        }
    }
}
int main()
{
    Try(1);
    return 0;
}
