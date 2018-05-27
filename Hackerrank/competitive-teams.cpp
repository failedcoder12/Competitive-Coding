// https://www.hackerrank.com/contests/world-codesprint-13/challenges/competitive-teams

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

ll ranks[100005];
ll parents[100005];
ll BIT[100005];
void update(ll i,ll inc,ll n){
    while(i<=n){
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}

int query(ll i){
    ll ans = 0;
    while(i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}
ll find(ll x){
    while(parents[x]!=x){
        x = parents[x];
    }
    return x;
}

ll unions(ll x,ll y){
    x = find(x);
    y = find(y);

    if(ranks[x] >= ranks[y]){
        parents[y] = parents[x];
        ranks[x] = ranks[x]+ranks[y];
        return ranks[x];
    }else {
        parents[x] = parents[y];
        ranks[y] = ranks[x]+ranks[y];
        return ranks[y];
    }
}
int main() {

    ll n,q;
    cin>>n>>q;
    memset(BIT,0,sizeof(BIT));

    for(ll i=1;i<=n;i++){
        parents[i] = i;
        ranks[i] = 1;
        update(ranks[i],1,n);
    }

    set<ll> s;
    s.insert(1);
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type == 1){
            ll x,y;
            cin>>x>>y;
            x = find(x);
            y = find(y);
            if(x == y){
                continue;
            }

            update(ranks[x],-1,n);

            ll get_x = query(ranks[x])-query(ranks[x]-1);

            if(get_x == 0){
                // if(s.find(ranks[x])!=s.end())
                s.erase(s.find(ranks[x]));
            }
            update(ranks[y],-1,n);

            ll get_y = query(ranks[y])-query(ranks[y]-1);


            if(get_y == 0){
                // if(s.find(ranks[y])!=s.end())
                s.erase(s.find(ranks[y]));
            }

            ll su = unions(x,y);
            update(su,1,n);
            s.insert(su);
        }
        else if(type == 2){

            ll c;
            cin>>c;

            ll ans = 0;
            for(auto x:s){
                if(c == 0){
                    ll pok1 = query(x) - query(x-1);
                    ll pok2 = 0;
                    if(x+c <= n){
                        pok2 = query(n)-query(x);
                    }
                    ans += (pok1*(pok1-1)/2);
                    ans += pok2*pok1;
                }else {
                    ll pok1 = query(x) - query(x-1);
                    ll pok2 = 0;
                    if(x+c <= n){
                        pok2 = query(n)-query(x+c-1);
                    }
                    ans += pok2*pok1;
                }
            }
            cout<<ans<<endl;
        }
    }
}