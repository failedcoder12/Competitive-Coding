// https://www.codechef.com/MARCH18B/problems/PSHTRG

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 50
 
ll segment_tree[1<<18][M];
ll ans[M];
ll temp[M];
void merge_single(ll *merge_node){
    ll j=0,k=0;
    for(ll i=0;i<M&&merge_node[i]&&k<M;i++){
        while(k<M && j<M && ans[j]>merge_node[i]){
            temp[k++] = ans[j++];
        }
        if(k<M){
            temp[k++] = merge_node[i];
        }
    }
 
    while(k<M && j<M && ans[j]){
        temp[k++] = ans[j++];
    }
    memcpy(ans, temp, static_cast<size_t>(k * sizeof(ll)));
}
 
void merge_three(ll *left_node,ll *right_node,ll *main_node){
    ll j=0,k=0;
    for(ll i=0;i<M&&left_node[i]&&k<M;i++){
        while(k<M && j<M && right_node[j]>left_node[i]){
            main_node[k++] = right_node[j++];
        }
        if(k<M){
            main_node[k++] = left_node[i];
        }
    }
 
    while(k<M && j<M && right_node[j]){
        main_node[k++] = right_node[j++];
    }
}
 
void build_tree(ll node,ll start,ll end,ll *input){
    if(start == end){
        segment_tree[node][0] = input[start];
        return;
    }
    ll mid = (start+end)/2;
    build_tree(2*node,start,mid,input);
    build_tree(2*node+1,mid+1,end,input);
    merge_three(segment_tree[2*node],segment_tree[2*node+1],segment_tree[node]);
}
 
void update_tree(ll node,ll start,ll end,ll *input,ll index,ll val){
    if(start == end){
        segment_tree[node][0] = val;
        return;
    }
    ll mid = (start+end)/2;
    if(index<=mid){
        update_tree(2*node,start,mid,input,index,val);
    }else {
        update_tree(2*node+1,mid+1,end,input,index,val);
    }
    merge_three(segment_tree[2*node],segment_tree[2*node+1],segment_tree[node]);
}
 
void query_tree(ll node,ll start,ll end,ll l,ll r){
    if(l<=start && end<=r){
        merge_single(segment_tree[node]);
        return;
    }
    ll mid = (start+end)/2;
    if(l<=mid){
        query_tree(2*node,start,mid,l,r);
    }
    if(mid+1<=r){
        query_tree(2*node+1,mid+1,end,l,r);
    }
 
}
 
int main(){
    ll n,q;
    cin>>n>>q;
    ll input[n+1];
    for(ll i=1;i<=n;i++){
        cin>>input[i];
    }
    build_tree(1,1,n,input);
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type == 1){
            ll pos,val;
            cin>>pos>>val;
            update_tree(1,1,n,input,pos,val);
        }else {
            memset(ans,0, sizeof(ans));
            ll l,r;
            cin>>l>>r;
            query_tree(1,1,n,l,r);
 
            ll perimeter = 0;
            for(ll i=0;i+2<M && ans[i+2];i++){
                if(ans[i]<ans[i+1]+ans[i+2]){
                    perimeter+= (ans[i]+ans[i+1]+ans[i+2]);
                    break;
                }
            }
            cout<<perimeter<<endl;
        }
    }
} 