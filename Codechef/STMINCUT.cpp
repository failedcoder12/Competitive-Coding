// https://www.codechef.com/problems/STMINCUT


// First solution dont know why it is correct second dolution learning soon

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n][n];
        ll check[n][n];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
                check[i][j] = a[i][j];
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                a[i][j] = max(a[i][j],a[j][i]);
            }
        }

        for(ll k=0;k<n;k++){
            for(ll i=0;i<n;i++){
                if(k!=i){
                    for(ll j=i+1;j<n;j++){
                        if(a[i][j] < min(a[i][k],a[k][j])){
                            a[i][j] = a[j][i] = min(a[i][k],a[k][j]);
                        }
                    }
                }
            }
        }

        ll sum = 0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                sum+= abs(a[i][j]-check[i][j]);
            }
        }
        cout<<sum<<endl;
    }

}


//Correct Solution as Editorial and logic

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
 
ll ranks[1001];
ll parents[1001];
 
// Union and find algorithm for krushkal's algorithm

ll find(ll x){
    while(parents[x]!=x){
        x = parents[x];
    }
    return x;
}
 
void unions(ll x,ll y){
    x = find(x);
    y = find(y);
 
    if(ranks[x] >= ranks[y]){
        parents[y] = x;
        ranks[x]++;
    }else {
        parents[x] = y;
        ranks[y]++;
    }
}

//DFS for distance from a node to all other node (min)
 
void dfs(ll u,ll v,ll m,vector<pair<ll,ll>> vc[],ll final_a[1001][1001],ll visit[]){
    visit[v] = 1;
    for(ll i=0;i<vc[v].size();i++){
        if(visit[vc[v][i].first] == 0){
            ll x = min(m,vc[v][i].second);
            final_a[u][vc[v][i].first] = x;
            dfs(u,vc[v][i].first,x,vc,final_a,visit);
        }
    }
}
 
 
int main(){
 
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
 
        ll final_a[1001][1001];
 
        memset(ranks,0, sizeof(ranks));
        for(int i=0;i<1001;i++)
            parents[i]=i;
 
        ll a[n][n];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
 
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                final_a[i][j] = max(a[i][j],a[j][i]);
            }
        }
 
        priority_queue<pair<ll,pair<ll,ll>>> pq;
 
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                pq.push(make_pair(final_a[i][j],make_pair(i,j)));
            }
        }
 
        ll count = 0;
        vector<pair<ll,ll>> vc[n];
 
        while(!pq.empty()){
            ll w = pq.top().first;
            ll u = pq.top().second.first;
            ll v = pq.top().second.second;
 
            pq.pop();
            ll x = find(u);
            ll y = find(v);
 
            if(x!=y){
                unions(x,y);
                vc[u].push_back(make_pair(v,w));
                vc[v].push_back(make_pair(u,w));
                count++;
            }
 
            if(count == n-1){
                break;
            }
        }
 
        memset(final_a,0, sizeof(final_a));
        ll visit[1001];
        for(ll i=0;i<n;i++){
            memset(visit,0, sizeof(visit));
            ll x = INT_MAX;
            dfs(i,i,x,vc,final_a,visit);
        }
 
        ll sum = 0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                sum += (final_a[i][j] - a[i][j]);
            }
        }
        cout<<sum<<endl;
    }
}