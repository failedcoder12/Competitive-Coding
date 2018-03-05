//http://www.spoj.com/problems/ARRAYSUB/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll k;
    cin>>k;
    deque<ll> q;
    for(ll i=0;i<k;i++){
        while(1){
            if(q.empty() || a[i] < a[*q.rbegin()]){
                break;
            }
            q.pop_back();
        }
        q.push_back(i);
    }
    for(ll i=k;i<n;i++){
        cout<<a[q.front()]<<" ";
        if(q.front() <= i-k ){
            q.pop_front();
        }
        while(1){
            if(q.empty() || a[i] < a[*q.rbegin()]){
                break;
            }
            q.pop_back();
        }q.push_back(i);
    }
    cout<<a[q.front()]<<endl;
    q.pop_back();
 
}