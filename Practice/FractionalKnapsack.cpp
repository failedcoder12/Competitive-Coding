#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1>r2;
}

int main(){
    ll W = 50;
    ll n=3;
    // First = value
    // Second = weight
    pair<ll,ll> item[n];
    item[0].first = 60;
    item[0].second = 10;
    item[1].first = 100;
    item[1].second = 20;
    item[2].first = 120;
    item[2].second = 30;
    sort(item,item+n,cmp);

    ll current = 0;
    double finalvalue = 0.0;
    for(ll i=0;i<n;i++){
        if(current + item[i].second <= W){
            current +=item[i].second;
            finalvalue+=item[i].first;
        }else {
            ll remain = W-current;
            finalvalue+=item[i].first * ((double)remain/item[i].second);
        }
    }
    cout<<finalvalue<<endl;
}