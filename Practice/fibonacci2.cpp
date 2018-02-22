
// Bottom Up Approach to Fibonacci Series

#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long int
#define MAX 1000000

ll fib[MAX];

int main(){

	fib[0] = 1;
	fib[1] = 1;

	ll n;
	cin>>n;
	for(ll i=2;i<n;i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	cout<<fib[n-1]<<endl;
}