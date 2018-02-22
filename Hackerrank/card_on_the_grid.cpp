// https://www.hackerrank.com/challenges/castle-on-the-grid/problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue<pair<ll,pair<ll,ll>>> q;
ll sx,sy,ex,ey;

bool visited[105][105];
char a[105][105];
ll bfs(ll n){

    pair<ll,pair<ll,ll>> p;
    ll ans = INT_MAX;
    q.push(make_pair(0,make_pair(sx,sy)));
    p.first = q.front().first;
    while(!q.empty()){
        ll pp = p.first = q.front().first;
        ll i = p.second.first = q.front().second.first;
        ll j = p.second.second = q.front().second.second;
        visited[i][j] = true;
        q.pop();
        if(i == ex && j == ey){
            return pp;
        }
        ll i1,i2,i3,i4;
        ll j1,j2,j3,j4;
        i1 = i2 = i3 = i4 = i;
        j1 = j2 = j3 = j4 = j;
        while(i1+1<n&&a[i1+1][j] == '.') {
            if(!visited[i1+1][j])
                q.push(make_pair(pp+1,make_pair(i1+1,j)));
            i1++;
        }
        while(j1+1<n&&a[i][j1+1] == '.'){
            if(!visited[i][j1+1])
                q.push(make_pair(pp+1,make_pair(i,j1+1)));
            j1++;
        }
        while(i2-1>=0&&a[i2-1][j] == '.') {
            if(!visited[i2-1][j])
                q.push(make_pair(pp+1,make_pair(i2-1,j)));
            i2--;
        }
        while(j2-1>=0&&a[i][j2-1] == '.'){
            if(!visited[i][j2-1])
                q.push(make_pair(pp+1,make_pair(i,j2-1)));
            j2--;
        }
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        for(ll j=0;j<t;j++){
            cin>>a[i][j];
        }
    }
    cin>>sx>>sy>>ex>>ey;
    cout<<bfs(t)<<endl;
}


