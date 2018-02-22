#include <bits/stdc++.h>
using namespace std;

int max_sub_array(int a[],int n){
    int ms = a[0];
    int cs = a[0];
    for(int i=1;i<n;i++){
        cs = max(a[i],cs+a[i]);
        ms = max(ms,cs);
    }
    return ms;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<max_sub_array(a,n);
}