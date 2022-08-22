#include<bits/stdc++.h>
using namespace std;
char *s = "abccaba";
char xc[3];
int k = 3;
int dem = 0;
int n = strlen(s);
bool comat(char a, char x[]){
	for(int i = 0; i < strlen(x); i++){
		if(x[i] == a){
			return true;
		}
	}
	return false;
}
void them(char x[], char a){
	int n = strlen(x);
	x[n] = a;
	x[n+1] = '\0';
}
void xoa(char x[]){
	int n = strlen(x);
	x[n-1] = '\0';
}
void ThucHien(int i){
	char tam[100];
	tam[0] ='\0';
	if(strlen(xc) == k){
		cout<<xc<<endl;
		dem++;
	}
	else{
		for(int j = i; j < n; j++){
			if(comat(s[j], tam) == false){
				them(tam, s[j]);
				them(xc, s[j]);
				ThucHien(j+1);
				xoa(xc);
			}
		}
	}
}
int main(){
	ThucHien(3);
}
