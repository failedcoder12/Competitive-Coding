//https://www.codechef.com/COOK94A/problems/CHEFTRVL

// dist(u,v) % 2=(dist(root,u) % 2)⊕(dist(root,v) % 2).
// dist(u, v) = dist(root, u) + dist(root, v) - 2 * dist(root, lca(u, v))

// Code taken from here need to do it again https://www.codechef.com/viewsolution/18611465

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
vector<ll> g[100001];
ll distancee[100001];
void dfs(ll node,ll parent){
    distancee[node] = distancee[parent] + 1;
    for(ll child:g[node]){
        if(child == parent){
            continue;
        }
        dfs(child,node);
    }
}

ll diff(ll x,ll y){
    if(x == 0&&y == 0){
        return 0;
    }
    if(x%2 == y%2){
        return diff(x/2,y/2);
    }
    return 1+ diff(x/2,y/2);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++) {
            g[i].clear();
            distancee[i] = -1;
        }
        for(ll i=0;i<n-1;i++){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0,0);
        ll ages[n];
        for(ll i=0;i<n;i++){
            cin>>ages[i];
        }

        ll size_1 = 0,size_2 = 0;
        for(ll i=0;i<n;i++) {
            ll check_1 = distancee[i] % 2;
            ll check_2 = diff(ages[0],ages[i])%2;
            if(check_1 == check_2){
                size_1++;
            }else {
                size_2++;
            }
        }
        cout<<size_1*size_2<<endl;
    }
}
