//https://www.codechef.com/problems/CD1IT4
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define MOD 1000000007
    int main(){
        ll m,n,t;
        cin>>m>>n>>t;
        ll a[m+1][n+1];
        memset(a,0,sizeof(a));
        for(ll j=0;j<t;j++){
            ll aa,bb;
            cin>>aa>>bb;
            a[aa][bb] = -1;
        }
     
        if(a[1][1] == -1){
            cout<<0<<endl;
            return 0;
        }
        a[1][1] = 1;
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                if(i==1 && j==1){
                    continue;
                }
                if(a[i][j] == -1){
                    continue;
                }
                a[i][j] = 0;
                if(a[i][j-1]!=-1){
                    a[i][j] = a[i][j-1]%MOD;
                }
                if(a[i-1][j]!=-1){
                    a[i][j] = (a[i][j]+a[i-1][j])%MOD;
                }
            }
        }
        if(a[m][n] == -1){
            cout<<0<<endl;
            return 0;
        }
        cout<<a[m][n]<<endl;
        // for(ll i=0;i<=m;i++){
        //     for(ll j=0;j<=n;j++){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
     
    } 