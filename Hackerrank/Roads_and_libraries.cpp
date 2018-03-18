// https://www.hackerrank.com/challenges/torque-and-development/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool visited[100001];

ll bfsutil(vector<ll> graph[],ll n,ll s){
    ll count = 0;
    queue<ll> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()){
        s = q.front();
        count++;
        q.pop();
        for(auto x:graph[s]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return count-1;
}

ll bfs(vector<ll> graph[],ll n,ll lib,ll road){

    ll count = 0;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            count+=(bfsutil(graph,n,i)*road + lib);
        }
    }
    return count;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        memset(visited,false,sizeof(visited));
        ll n,m,lib,road;
        cin>>n>>m>>lib>>road;
        vector<ll> graph[n+1];
        for(ll i=1;i<=m;i++){
            ll s,d;
            cin>>s>>d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        
        if(road>=lib){
            cout<<(lib*n)<<endl;
        }else {
            cout<<bfs(graph,n,lib,road)<<endl;    
        }
    }
}
