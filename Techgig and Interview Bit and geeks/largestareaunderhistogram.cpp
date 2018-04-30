// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/

#include<bits/stdc++.h>
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

        stack<ll> s;
        ll max_area = 0;
        ll i = 0;
        while(i<n){
            if(s.empty()||a[i]>=a[s.top()]){
                s.push(i++);
            }else {
                ll x = s.top();
                s.pop();
                if(!s.empty())
                    max_area = max(max_area,a[x]*(i-s.top()-1));
                else
                    max_area = max(max_area,a[x]*(i));
            }
            // cout<<max_area<<" ";
        }
        while(!s.empty()){
            ll x = s.top();
            s.pop();
                if(!s.empty())
                    max_area = max(max_area,a[x]*(i-s.top()-1));
                else
                    max_area = max(max_area,a[x]*(i));
            }
        cout<<max_area<<endl;
    }
}