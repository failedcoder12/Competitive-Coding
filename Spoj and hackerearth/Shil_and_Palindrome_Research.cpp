// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll siz = 100003;
ll bit[100003][26];
void update(ll i,ll inc,ll v){
    while(i<=siz){
        bit[i][v]+=inc;
        i+=(i & -i);
    }
}
 
ll query(ll i,ll v){
    ll ans = 0;
    while(i>0){
        ans+=bit[i][v];
        i-=(i&(-i));
    }
    return ans;
}
 
int main(){
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i] = c-'a';
        update(i,1,c-'a');
    }
    for(ll i=0;i<q;i++){
        ll type;
        cin>> type;
        if(type == 1){
            ll l; char x;
            cin>>l>>x;
            update(l,-1,a[l]);
            update(l,1,x-'a');
            a[l] = x-'a';
        }else {
            ll l,r;
            cin>>l>>r;
            ll count[26] = {0};
            for(ll j=0;j<26;j++){
                count[j]+= query(r,j);
            }
            for(ll j=0;j<26;j++){
                count[j]-= query(l-1,j);
            }
            ll pp = 0;
            for(ll j=0;j<26;j++){
                if(count[j]%2!=0){
                    pp++;
                }
            }
            if(pp>1){
                cout<<"no"<<endl;
            }else {
                cout<<"yes"<<endl;
            }
        }
    }
 
}