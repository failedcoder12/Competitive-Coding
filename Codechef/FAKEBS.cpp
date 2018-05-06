// https://www.codechef.com/MAY18B/problems/FAKEBS

#include<iostream>
#include<unordered_map>
#include<vector>
#include <algorithm> 
using namespace std;
#define ll long int
 
vector<ll> binarySearch(ll l,ll r,ll x,ll b[])
{
    vector<ll> path;
    while (l <= r)
    {
        ll m = l + (r-l)/2;
        // cout<<m<<"}"<<ma[m]<<"}}";
        path.push_back(b[m]);
        if (m == x) {
            return path;
        }
        else if (m < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
 
}
 
int main(){
    ll t;
    scanf("%ld",&t);
    // cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        unordered_map<ll,ll> index,ma;
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            scanf("%ld",&a[i]);
            b[i] = a[i];
        }
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            index[a[i]] = i;
        }
        for(ll i=0;i<n;i++){
            b[i] = index[b[i]];
            ma[b[i]] = i;
        }
 
 
        for(ll i=0;i<q;i++){
            ll x;
            scanf("%ld",&x);
            x = index[x];
            ll left_=0,right_=0,cl=0,cr=0;
            vector<ll> path = binarySearch(0,n-1,ma[x],b);
            for(auto v:path){
                // cout<<v+1<<"->";
                if(v == x){
                    continue;
                }
                else if(ma[v] < ma[x] && v<x){
                    cr++;
                }
                
                else if(ma[v] > ma[x] && v > x){
                    cl++;
                }
                else if(ma[v] < ma[x] && v > x){
                    left_++;
                }
                else if(ma[v] > ma[x] && v < x){
                    right_++;
                }
            }
            // cout<<left_<<": "<<right_<<" : "<<x<<endl;
            if(left_ > x-cr || right_ > n-1-x-cl){
                printf("%d\n",-1);
                continue;
            }
 
            if(left_ >= right_){
                printf("%ld\n",left_);
            }else {
                printf("%ld\n",right_);
            }
        }
 
    }
}   