#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL

ll a[100],b[100];

void ans(){
    a[0] = 1;
    b[0] = 1;
    for(ll i=1;i<=100;i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
}

int main(){
    ll t;
    cin>>t;
    ans;
    while(t--) {
        ll n;
        cin >> n;
        cout<<a[n]<<endl;
    }
}