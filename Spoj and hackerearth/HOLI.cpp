// http://www.spoj.com/problems/HOLI/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
 
#define N 100010
 
vector<ll> g[N],w[N];
bool visited[N];
ll ans[N];
ll n;
ll res;
 
void dfs(ll v){
    visited[v] = true;
    for(ll i=0;i<g[v].size();i++){
        ll u = g[v][i];
        if(!visited[u]){
            dfs(u);
            res+=min(ans[u],n-ans[u]) * 2 * w[v][i];
            ans[v] += ans[u];
        }
    }
}
 
int main(){
 
    ll tt;
    cin>>tt;
    for(ll t=1;t<=tt;t++){
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
            w[i].clear();
            visited[i] = false;
            ans[i] = 1;
        }
        for(ll i=0;i<n-1;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            --x,--y;
            g[x].push_back(y);
            g[y].push_back(x);
            w[x].push_back(z);
            w[y].push_back(z);
        }
        res = 0;
        dfs(0);
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
} 