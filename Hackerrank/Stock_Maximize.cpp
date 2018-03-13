// https://www.hackerrank.com/challenges/stockmax/problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll maxso = a[n-1];
        ll sum = 0;
        for(ll i = n-1;i>=0;i--){
            if(a[i]>maxso){
                maxso = a[i];
            }
            sum+= maxso-a[i];
        }
        cout<<sum<<endl;
    }
}