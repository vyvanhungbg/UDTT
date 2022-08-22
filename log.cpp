#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct GH
{
    char ma[20];
    int kl;
    int gt;
    GH(char *ma, int kl, int gt)
    {
        strcpy(this->ma, ma);
        this->kl = kl;
        this->gt = gt;
    }
    GH() {}
};
//
void view(GH a[], int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i].ma<<setw(10)<<a[i].kl<<setw(10)<<a[i].gt<<endl;
}
//
int binarySearch(GH a[], int left, int right, char *ma)
{
    if(left <= right)
    {
        int mid = (left + right) / 2;
        if(strcmp(a[mid].ma, ma)==0)
            return mid;
        else if(strcmp(a[mid].ma, ma)==-1)
            return binarySearch(a, mid+1, right, ma);
        else
            return binarySearch(a, left, mid-1, ma);
    }
    return -1;
}
//
int dp[7][101];
int w = 50;

// th lấy gói hàng    i  : gt = dp[i][j] , từ gói hàng dp[i-1][j-a[i].kl] + a[i].gt đến
// th ko lay goi hang i  : gt = dp[i][j] , từ gói hàng dp[i-1][j] đến
void QuyHoachDong(GH a[], int n)
{
    // khoi tao

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i == 0 || j==0)  // gia su lay goi thu 0 deu mang gia tri la 0
                dp[i][j] =0;
            // khong lay goi i
            dp[i][j] = dp[i-1][j];

            int tmp = dp[i-1][j-a[i].kl] + a[i].gt;
            if(tmp > dp[i][j] && j >= a[i].kl)
                dp[i][j] = tmp;
        }
    }
}



int TimMaxKL(GH a[], int left, int right)
{
    //cout << left << " "<< right <<endl;
    if(left == right)
    {
        //cout<< "return a["<<left<<"] = "<<a[left].kl<<endl;
        return a[left].kl;
    }
    else
    {
        int mid = (left + right ) / 2;
        return min(TimMaxKL(a,left, mid), TimMaxKL(a, mid+1, right));
    }
}

int TinhTong(GH a[], int left, int right)
{
    if(left == right)
        return a[left].kl;
    else
    {
        int mid = (left + right ) / 2;
        return TinhTong(a, left, mid) + TinhTong(a, mid +1, right);
    }
}

// Lap
int indexOf(char *str, char *t)
{
    int lengh_str = strlen(str);
    int lengh_t = strlen(t);
    for(int i=0; i<lengh_str-lengh_t+1; i++)
    {
        int j =0;
        while(j < lengh_t && t[j] == str[j+i])
            j++;
        if(j==lengh_t)
            return i;
    }
    return -1;
}
// BMH
int char_in_str(char *str, char t)
{
    int n = strlen(str);
    for(int i=0; i<n; i++)
        if(str[i]==t)
            return i;
    return -1;
}
int BMH(char *str, char *t)
{
    int dem = 0, v = strlen(t), i = strlen(t);
    while(i<=strlen(str))
    {
        int x = v-1, j = i-1;
        while(x>-1 && t[x] == str[j])
        {
            x--;
            j--;
        }
        if(x <0)
        {
            dem++;
            i = i+v;
        }else
        {
            x = char_in_str(t, str[x]);
            if(x >0)
                i = i+v;
            else
                i = i+v-x-1;
        }
    }
    return dem;
}
// LCM
int L[100][100];
void algorithm(char *A , char *B)
{


    for (int i = 0; i < strlen(A); i++) L[i][0] = 0;
    for (int j = 0; j < strlen(B); j++) L[0][j] = 0;


    for (int i = 0; i < strlen(A); i++)
        for (int j = 0; j < strlen(B); j++)
            if (A[i] == B[j])
                    L[i][j] = L[i-1][j-1] + 1;
                    else
                        L[i][j] = 0;
    cout<<endl;

     for (int i = 0; i < strlen(A); i++)
        {
            for (int j = 0; j <strlen(B); j++)
            cout<<L[i][j]<<" ";
            cout<<endl;
        }

}

// Z fun
void z_algo(const char *s, int *z)
{
    int n = strlen(s), l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r - l]== s[r]) r++;
            z[i] = r - l;
            r --;
        }
        else if (z[i - l] < r - i + 1)
            z[i] = z[i-l];
        else
        {
            l = i;
            while (r < n && s[r - l] == s[r]) r ++;
            z[i] = r - l;
            r --;
        }
    }
}
int z[100];

// So thanh tong
int f[6][8];
void PhanTichSoThanhTong(int n, int m)
{
    f[0][0] =1 ;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i < j)
                f[i][j] = f[i][j-1];
            else
            {
                f[i][j] = f[i][j-1] + f[i-j][j];
            }
        }
    }
    cout << f[n][n]<<endl;
}

// fibo nan
//int *f, n;
//int fibo(int n) {
//	f[1] = f[2] = 1;
//	for (int i = 3; i <= n; i++){
//		f[i] = f[i - 1] + f[i - 2];
//	}
//	return f[n];
//}
//int fibo1(int n) {
//	int f1 = 1, f2 = 1, f3;
//	for (int i = 3; i <= n; i++){
//		f3 = f2 + f1;
//		f1 = f2;
//		f2 = f3;
//	}
//	return f3;
//}
int main()
{
    char str[] = "namsau$mothaibabonnamsau";
    char t[]  = "nam";
    //cout<<indexOf(str, t);
    cout<<BMH(str,t)<<endl;

    z_algo(str,z);
    for(int i=0; i<strlen(str); i++)
        cout<<z[i]<< " ";

    return 0;
}
