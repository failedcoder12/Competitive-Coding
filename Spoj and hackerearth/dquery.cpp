   // http://www.spoj.com/problems/DQUERY/
    #include <bits/stdc++.h>
    using namespace std;
    #define ll int
     
    ll bit[300005];
    ll cumm[1000005];
     
    void update(ll i,ll val){
        while(i<=300005){
            bit[i] += val;
            i+=(i & -i);
        }
    }
     
    ll query(ll i){
        ll ans = 0;
        while(i>0){
            ans+=bit[i];
            i -= (i & -i);
        }
        return ans;
    }
     
    bool sortsec(const pair<pair<ll,ll>,ll>&a,const pair<pair<ll,ll>,ll>&b){
        return a.first.second<b.first.second;
    }
     
    int main(){
        ll n;
        scanf("%d",&n);
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ll q;
        scanf("%d",&q);
        pair<pair<ll,ll>,ll> que[q];
        for(ll i=0;i<q;i++){
     
            scanf("%d%d",&que[i].first.first,&que[i].first.second);
            que[i].second = i;
        }
        ll ans[q];
        memset(cumm,-1, sizeof(cumm));
        sort(que,que+q,sortsec);
        ll r = 0;
        for(ll i=1;i<=n;i++){
            if(cumm[a[i]] != -1){
                update(cumm[a[i]],-1);
            }
            cumm[a[i]] = i;
            update(i,1);
            while(r<q && i == que[r].first.second){
                ans[que[r].second] = query(que[r].first.second) - query(que[r].first.first-1);
                r++;
            }
        }
        for(ll i=0;i<q;i++){
            printf("%d\n",ans[i]);
        }
    } 