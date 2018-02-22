#include <bits/stdc++.h>
using namespace std;

int maxsufpre(int a[],int s,int mid,int e){
    int sum = 0;
    int left = INT_MIN;
    for(int i = mid;i >= s;i--){
        sum+=a[i];
        if(sum>left){
            left = sum;
        }
    }
    sum = 0;
    int right = INT_MIN;
    for(int i = mid+1;i <= s;i++) {
        sum += a[i];
        if (sum > right) {
            right = sum;
        }
    }
    return left+right;
}

int max_sub_array(int a[],int s,int e){
    if(s==e)
        return a[s];
    int mid = (s+e)/2;

    return max(max(max_sub_array(a,s,mid),max_sub_array(a,mid+1,e)),
              maxsufpre(a,s,mid,e));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<max_sub_array(a,0,n-1);
}