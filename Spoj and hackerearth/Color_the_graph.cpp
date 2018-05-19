// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/color-the-graph/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL

class Graph {
public:
    ll V;
    list<ll> *l;

    Graph(ll v){
        V = v;
        l = new list<ll>[V];
    }

    void addEdge(ll u,ll v,bool bidir = true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

    ll coloring(ll s,vector<ll> &color){
        ll ans[2];
        ans[0] = 0,ans[1] = 0;
        queue<ll> q;
        q.push(s);
        color[s] = 1;
        while(!q.empty()){
            ll u = q.front();
            ans[color[u]] ++;
            q.pop();
            for(auto v:l[u]){
                if(color[v] == -1){
                    color[v] = 1-color[u];
                    q.push(v);
                }else if(color[v] == color[u]){
                    return -1;
                }
            }
        }
        return max(ans[0],ans[1]);
    }
    
    ll truecolor(){
         vector<ll> color(V);
        for(ll i=0;i<V;i++){
            color[i] = -1;
        }
        ll ans = 0;
        for(ll i=0;i<V;i++){
            if(color[i]==-1){
                ll temp =coloring(i,color);
                if(temp == -1){
                    return -1;
                }
                ans+=temp;
            }
        }
        return ans;
    }
};

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        Graph g(n);
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        ll ans = g.truecolor();
        if(ans == -1){
            cout<<"NO"<<endl;
        }else {
            cout<<ans<<endl;
        }
    }
}