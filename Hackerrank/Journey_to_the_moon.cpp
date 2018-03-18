// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll parent[100001];
ll priority[100001];
ll counut[100001];

ll find(ll a){
    while(parent[a] != a){
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

void cc(ll a){
    if(parent[a] == a){
        counut[a]++;
    }else{
        cc(parent[a]);
    }
}

void uni(ll a,ll b){
    if(priority[a] < priority[b]){
        parent[a] = parent[b];
        priority[b]+=priority[a];
    }else {
        parent[b] = parent[a];
        priority[a]+=priority[b];
    }
}


int main(){

    ll n,p;
    cin>>n>>p;

    for(ll i=0;i<n;i++){
        parent[i] = i;
        priority[i]= 1;
    }
    for(ll i=0;i<p;i++){
        ll a,b;
        cin>>a>>b;
        ll xx = find(a);
        ll yy = find(b);
        if(xx==yy)
            continue;
        else
            uni(xx,yy);
    }

    for(ll i=0;i<n;i++){
        cc(i);
    }

    ll total = 0;
    unordered_map<ll,ll> un;
    for(ll i=0;i<n;i++){
        if(counut[i]!=0){
            total+=counut[i];
            un[i] = counut[i];
        }
    }

    ll sum[un.size()];
    ll ii = 0;
    ll solution = 0;
    ll pre = 0;
    for(auto it:un){
        pre+=it.second;
        sum[ii++]  = total-pre;
        solution+= it.second * sum[ii-1];
    }
    cout<<solution<<endl;
}
