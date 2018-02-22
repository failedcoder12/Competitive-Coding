
//https://www.codechef.com/NOV17/problems/CSUBQ

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    ll left[2],right[2];
    ll len,ans[2];
}tree[2000008];

ll getValue(ll x,ll L,ll R){
    if(x<L){
        return 1;
    }else if(x<R){
        return 2;
    }
    return 0;
}

struct node mergenodes(struct node l,struct node r,ll x1,ll x2){
    struct node fi;
    for(int i=0;i<2;i++){
        fi.left[i] = l.left[i];
        if(l.left[i] == x1){
            fi.left[i]+=r.left[i];
        }
        fi.right[i] = r.right[i];
        if(r.right[i] == x2){
            fi.right[i]+=l.right[i];
        }
        fi.ans[i] = l.ans[i] + r.ans[i] +(l.right[i] * r.left[i]);
    }
    return fi;
}

void buildtree(ll left,ll right,ll root,ll L){
    if(left==right){
        for(int i=0;i<2;i++) {
            tree[root].left[i] = tree[root].right[i] = tree[root].ans[i] = 1;
//            tree[root].len = right -  + 1;
        }
        return;
    }
    ll mid = (left+right)/2;
    buildtree(left,mid,root*2,L);
    buildtree(mid+1,right,root*2+1,L);
    tree[root] = mergenodes(tree[root*2],tree[root*2+1],mid-left+1,right-mid);
}

void update(ll left,ll right,ll x,ll val,ll root){
    if(left>x||right<x){
        return;
    }
    if(left==right){
        if(val == 1){
            tree[root].ans[0] = tree[root].left[0] = tree[root].right[0] = 1;
            tree[root].ans[1] = tree[root].left[1] = tree[root].right[1] = 1;
        }else if(val == 2){
            tree[root].ans[0] = tree[root].left[0] = tree[root].right[0] = 1;
            tree[root].ans[1] = tree[root].left[1] = tree[root].right[1] = 0;
        }else {
            tree[root].ans[0] = tree[root].left[0] = tree[root].right[0] = 0;
            tree[root].ans[1] = tree[root].left[1] = tree[root].right[1] = 0;
        }
        return;
    }
    ll mid = (left+right)/2;
    update(left,mid,x,val,2*root);
    update(mid+1,right,x,val,2*root+1);
    tree[root] = mergenodes(tree[root*2],tree[root*2+1],mid-left+1,right-mid);
}


struct node ans(ll l,ll r,ll left,ll right,ll root){
    if(left>=l&&right<=r){
        return tree[root];
    }
    ll mid = (left+right)/2;
    if(r<=mid){
        return ans(l,r,left,mid,2*root);
    }
    if(l>mid)
        return ans(l,r,mid+1,right,2*root+1);
    return mergenodes(ans(l,r,left,mid,2*root),ans(l,r,mid+1,right,2*root+1),mid-left+1,right-mid);
}

int main() {
    ll n,q,l,r;
    scanf("%lld %lld %lld %lld",&n,&q,&l,&r);
    buildtree(1,n,1,l);
    while(q--){
        ll type,x,y;
        scanf("%lld %lld %lld",&type,&x,&y);
        if(type==1){
            update(1,n,x,getValue(y,l-1,r),1);
        }else {
            struct node t = ans(x,y,1,n,1);
            printf("%lld\n",t.ans[0]-t.ans[1]);
        }
    }
}