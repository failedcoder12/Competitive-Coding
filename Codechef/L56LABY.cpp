//https://www.codechef.com/problems/L56LABY
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll a[1001][1001];

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;

        cin>>n>>m;
        set<pair<ll,pair<ll,ll>>> s;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]!=0&&a[i][j]!=-1){
                    a[i][j] = a[i][j]+1;
                    s.insert(make_pair(a[i][j],make_pair(i,j)));
                }
            }
        }
        
        while(!s.empty()){
            auto p = *s.rbegin();
            ll i,j,val;
            i = p.second.first;
            j = p.second.second;
            val = p.first;
            if(i-1>=0){
                if(val > 0 && val > a[i-1][j] && a[i-1][j] !=-1) {
                    a[i - 1][j] = val - 1;
                    s.insert(make_pair(a[i-1][j],make_pair(i-1,j)));
                }
            }if(i+1<n) {
                if (val > 0 && val > a[i + 1][j] && a[i + 1][j] != -1) {
                    a[i + 1][j] = val - 1;
                    s.insert(make_pair(a[i+1][j],make_pair(i+1,j)));
                }
            }if(j-1>=0){
                if(val > 0 && val > a[i][j-1] && a[i][j-1] !=-1) {
                    a[i][j - 1] = val - 1;
                    s.insert(make_pair(a[i][j-1],make_pair(i,j-1)));
                }
            }if(j+1<m){
                if(val > 0 && val > a[i][j+1] && a[i][j+1] !=-1) {
                    a[i][j + 1] = val - 1;
                    s.insert(make_pair(a[i][j+1],make_pair(i,j+1)));
                }
            }
            s.erase(p);
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(a[i][j]==0){
                    cout<<"N";
                }else if(a[i][j] == -1){
                    cout<<"B";
                }else {
                    cout<<"Y";
                }
            }
            cout<<endl;
        }
    }
}