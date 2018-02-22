#include<bits/stdc++.h>
using namespace std;

int a[100000];
int BIT[100000];

void update(int i,int inc,int n){
    while(i<=n){
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}

int query(int i){
    int ans = 0;
    while(i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
}