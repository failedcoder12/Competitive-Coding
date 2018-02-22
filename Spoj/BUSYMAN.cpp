//http://www.spoj.com/problems/BUSYMAN/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return (a.second<b.second);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        pair<ll,ll> job[n];
        for(ll i=0;i<n;i++){
            ll start,end;
            cin>>start>>end;
            job[i].first = start;
            job[i].second = end;
        }
        sort(job,job+n,compare);
        ll count = 1;
        ll i=0;
        for(ll j=1;j<n;j++){
            if(job[j].first >= job[i].second){
                count++;
                i = j;
            }
        }
        cout<<count<<endl;
    }
}