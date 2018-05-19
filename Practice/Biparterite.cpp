#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL

class Graph {
    ll V;
    list<ll> *l;

public:
    Graph(ll v){
        V =v;
        l = new list<ll>[V];
    }

    void addEdge(ll u,ll v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isBipartite(ll s){

        queue<ll> q;
        q.push(s);
        ll *colors = new ll[V];
        for(ll i=0;i<V;i++){
            colors[i] = -1;
        }
        colors[s] = 0;
        bool ans = true;

        while(!q.empty()&&ans){
            ll u = q.front();
            q.pop();

            for(auto v:l[u]){
                if(colors[v] == -1){
                    colors[v] = 1-colors[u];
                    q.push(v);
                }else if(colors[v] == colors[u]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,3);
    g.addEdge(2,3);

    if(g.isBipartite(0)){
        cout<<"Yes it is Bipar";
    }else {
        cout<<"It is not";
    }


}