// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define hashmap unordered_map<ll,list<ll>>
class Graph{
public:
	hashmap h;
	bool visited[110];
	Graph(){
		for(ll i=0;i<110;i++){
			visited[i] = 0;
		}
	}
	void addEdge (ll u,ll v){
		h[u].push_back(v);
	}
	ll bfs(){
		queue<pair<ll,ll>> q;
		q.push(make_pair(1,0));
		while(!q.empty()){
		    
			ll xx = q.front().first;
			ll inc = q.front().second;
					visited[xx] = true;
			if(xx == 100){
				return inc;
			}
			q.pop();
			for(auto x:h[xx]){
				if(!visited[x]){
					q.push(make_pair(x,inc+1));
				}
			}
		}
        return -1;
	}
};

int main(){

ll t;
cin>>t;
while(t--){
Graph g;
unordered_map<ll,ll> hh;
for(ll i=0;i<=116;i++){
	hh[i] = i;
}
ll n;
cin>>n;
for(ll i=0;i<n;i++){
	ll u,v;
	cin>>u>>v;
	hh[u] = v;
}

ll m;
cin>>m;
for(ll i=0;i<m;i++){
	ll u,v;
	cin>>u>>v;
	hh[u] = v;
}

for(ll i=0;i<=100;i++){
	for(ll j=i+1;j<=i+6;j++){
		g.addEdge(i,hh[j]);
	}
}

cout<<g.bfs()<<endl;
}
}