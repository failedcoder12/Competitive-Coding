
// Fibonacci series using Matrix Exponentiation

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 1000000

void multiply(ll a[3][3],ll b[3][3]){
	ll mul[3][3];
	for(ll i=0;i<3;i++){
		for(ll j=0;j<3;j++){
		mul[i][j]=0;
		for(ll k=0;k<3;k++){
			mul[i][j]+=a[i][k]*b[k][j];
		}
	}
	}
	for(ll i=0;i<3;i++){
		for(ll j=0;j<3;j++){
			a[i][j]=mul[i][j];
		}
	}
}

ll powerr(ll F[3][3],ll n){
	ll M[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
	if(n==1)
		return F[0][0] + F[0][1];
	powerr(F,n/2);
	multiply(F,F);
	if(n%2!=0)
		multiply(F,M);
	return F[0][0]+F[0][1];
}

ll FFiibboo(ll n){
	ll F[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
	return powerr(F,n-2);
}

int main(){
	ll n=5;
	cout<<FFiibboo(n)<<endl;
}