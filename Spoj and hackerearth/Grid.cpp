// https://www.hackerearth.com/challenge/competitive/airtel-crack-the-code/algorithm/robot-in-grid-b7d391f7/

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
     
    struct point {
        ll x,y,c;
    };
    ll a[1001][1001];
    ll ans[1001][1001];
    bool visited[1001][1001];
    void maze(ll a[1001][1001],ll n,ll m,ll s,ll e){
        queue<struct point> q;
        ans[s][e]=0;
        q.push({s,e,0});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            ll i = x.x;
            ll j = x.y;
            ll cc = x.c;
            if(i+1 <=n && !visited[i+1][j] && a[i+1][j] != -1 && ans[i+1][j] == -1){
                ans[i+1][j] = cc+1;
                visited[i+1][j] = true;
                q.push({i+1,j,cc+1});
            }
            if(j+1 <= m && !visited[i][j+1] && a[i][j+1] != -1&& ans[i][j+1] == -1){
                ans[i][j+1] = cc+1;
                visited[i][j+1] = true;
                q.push({i,j+1,cc+1});
            }
            if(i-1 >=1 && !visited[i-1][j] && a[i-1][j] != -1&& ans[i-1][j] == -1){
                ans[i-1][j] = cc+1;
                visited[i-1][j] = true;
                q.push({i-1,j,cc+1});
            }
            if(j-1>=1 && !visited[i][j-1] && a[i][j-1] != -1&& ans[i][j-1] == -1){
                ans[i][j-1] = cc+1;
                visited[i][j-1] = true;
                q.push({i,j-1,cc+1});
            }
        }
    }
     
    int main(){
        ll n,m,q;
        cin>>n>>m>>q;
        memset(ans,-1,sizeof(ans));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                char x;
                cin>>x;
                if(x == 'O'){
                    a[i][j] = 1;
                }else {
                    a[i][j] = -1;
                }
            }
        }
     
        ll s,e;
        cin>>s>>e;
        maze(a,n,m,s,e);
		for(ll i=0;i<q;i++){
            ll q1,q2;
            cin>>q1>>q2;
            cout<<ans[q1][q2]<<endl;
        }
    }