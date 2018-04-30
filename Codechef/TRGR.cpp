// https://www.codechef.com/LOCAPR18/problems/TRGR

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
unordered_map<ll,pair<ll,ll>> graph_at_tree;
 
ll find(ll i,vector<ll> &parent){
    while(i!=parent[i]){
        i = parent[i];
    }
    return parent[i];
}
 
void DFS(vector<vector<ll>> &tree,ll node,vector<ll> &parent,vector<ll> &size,ll pare,vector<ll> &ans,ll count){
    if(node >= tree.size()){
        return;
    }
 
    ll u = graph_at_tree[node].first;
    ll v = graph_at_tree[node].second;
 
    ll parent_u = find(u,parent);
    ll parent_v = find(v,parent);
 
    ll which = -1;
    if(parent_u!=parent_v){
        if(size[parent_u]<size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
            which = 1;
        }else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
            which = 2;
        }
        count--;
    }
    ans[node] = count;
    
    for(ll i=0;i<tree[node].size();i++){
        if(tree[node][i]!=pare){
            DFS(tree,tree[node][i],parent,size,node,ans,count);
        }
    }
    
    if(which == 1){
        parent[parent_u] = parent_u;
        size[parent_v] -= size[parent_u];
    }else if(which == 2){
        parent[parent_v] = parent_v;
        size[parent_u] -= size[parent_v];
    }
    
}
 
int main(){
 
    ll n;
    cin>>n;
 
    vector<ll> parent(n);
    vector<ll> size(n,1);
    for(ll i=0;i<n;i++){
        parent[i] = i;
    }
    vector<vector<ll>> tree(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
 
    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        graph_at_tree[i].first = u-1;
        graph_at_tree[i].second = v-1;
    }
 
    vector<ll> ans(n,-1);
 
    DFS(tree,0,parent,size,-1,ans,n);
    
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
} 