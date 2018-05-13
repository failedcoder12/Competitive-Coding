// http://codeforces.com/contest/976/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct pt{
    ll x,y,i;
};

pair<ll,ll> pt2;
bool comp(const pt &a,const pt &b) {
    if(a.x < b.x){
        return true;
    }else if(a.x == b.x){
        return a.y>b.y;
    }
    return false;
};

int main(){

    ll n;
    cin>>n;
    struct pt p[n];
    for(ll i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].i = i;
    }

    sort(p,p+n,comp);

    set<pair<ll,ll>> cur;

    for(ll i=0;i<n;i++){
        
        if(!cur.empty() && (--cur.end())->first >= p[i].y){
            cout<<p[i].i+1<<" "<<(--cur.end())->second + 1<<endl;
            return 0;
        }
        cur.insert(make_pair(p[i].y,p[i].i));
    }
    cout<<"-1 -1"<<endl;
}