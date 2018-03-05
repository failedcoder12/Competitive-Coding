
//http://www.spoj.com/problems/MST1/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    ll n;
    cin>>n;
    ll a[20000001];
    a[0] = 0;
    a[1] = 0;
    for(ll i=2;i<20000001;i++){
        a[i] = a[i-1]+1;
        if(i%2==0){
            a[i] = min(a[i],a[i/2]+1);
        }
        if(i%3==0){
            a[i] = min(a[i],1+a[i/3]);
        }
    }
    for(ll i=0;i<n;i++){
        ll t;
        cin>>t;
        cout<<"Case "<<i+1<<": "<<a[t]<<endl;
    }
 
} 