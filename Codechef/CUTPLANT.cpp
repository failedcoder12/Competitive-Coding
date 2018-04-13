// https://www.codechef.com/APRIL18B/problems/CUTPLANT/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100020];
ll b[100020];
 
ll max_seg[400080];
ll min_seg[400080];
 
bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a.first < b.first){
        return true;
    }
    if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
    }
    return false;
}
void constructST_min(ll  ss,ll  se,ll si)
{
    if (ss > se) return ;
    if (ss == se)
    {
        min_seg[si] = a[ss];
        return;
    }
    ll mid = (ss + se)/2;
    constructST_min( ss, mid, si*2+1);
    constructST_min( mid+1, se, si*2+2);
    min_seg[si] = min(min_seg[si*2 + 1] , min_seg[si*2 + 2]);
}
 
ll query_min(ll ss,ll se,ll si,ll l,ll r)
{
    if(l<=ss && r>=se)
    {
        return min_seg[si];
    }
    else if(l>se || r<ss)
    {
        return INT_MAX;
    }
    ll mid=(ss+se)/2;
    return min(query_min(ss,mid,2*si+1,l,r),query_min(mid+1,se,2*si+2,l,r));
}
 
void constructST_max(ll  ss,ll  se,ll si)
{
    if (ss > se) return ;
    if (ss == se)
    {
        max_seg[si] = b[ss];
        return;
    }
    ll mid = (ss + se)/2;
    constructST_max( ss, mid, si*2+1);
    constructST_max( mid+1, se, si*2+2);
    max_seg[si] = max(max_seg[si*2 + 1] , max_seg[si*2 + 2]);
}
 
ll query_max(ll ss,ll se,ll si,ll l,ll r)
{
    if(l<=ss && r>=se)
    {
        return max_seg[si];
    }
    else if(l>se || r<ss)
    {
        return INT_MIN;
    }
    ll mid=(ss+se)/2;
    return max(query_max(ss,mid,2*si+1,l,r),query_max(mid+1,se,2*si+2,l,r));
}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        memset(max_seg,0, sizeof(max_seg));
        memset(min_seg,0, sizeof(min_seg));
        ll n;
        cin>>n;
        ll ans[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
       vector<pair<ll,ll>> p;
        bool check = false;
        for(ll i=0;i<n;i++){
            cin>>b[i];
            if(b[i] == a[i]){
                ans[i] = 0;
            }else if(b[i]>a[i]){
                check = true;
            }else {
                p.push_back(make_pair(b[i],i));
                ans[i] = 1;
            }
        }
        if(check){
            cout<<-1<<endl;
            continue;
        }
        if(p.size() == 1){
            cout<<1<<endl;
            continue;
        }
        if(p.size() == 0){
            cout<<0<<endl;
            continue;
        }
        sort(p.begin(),p.end(),compare);
        // for(ll i=0;i<p.size();i++) cout<<p[i].first<<" "<<p[i].second<<endl;
        constructST_max(0,n-1,0);
        constructST_min(0,n-1,0);
        for(ll i=0;i<p.size()-1;i++){
            if(p[i].first == p[i+1].first){
                ll min_in_a = query_min(0,n-1,0,p[i].second,p[i+1].second);
                ll max_in_b = query_max(0,n-1,0,p[i].second,p[i+1].second);
                if(min_in_a >= b[p[i].second] && max_in_b <= b[p[i].second]){
                    ans[p[i].second] = 0;
                }
            }
        }
        ll total = 0;
        // for(ll i=0;i<n;i++) cout<<ans[i]<<endl;
        for(ll i=0;i<n;i++){
            if(ans[i]){
                total++;
            }
        }
        cout<<total<<endl;
    }
}