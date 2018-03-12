#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> initialize(vector<ll> &A){
    ll size = A.size();
    vector<ll> D(size+1);

    D[0] = A[0];
    D[size] = 0;
    for(ll i=1;i<size;i++){
        D[i] = A[i] - A[i-1];
    }
    return D;
}

void Update(vector<ll> &D,ll l,ll r,ll val){
    D[l] += val;
    D[r+1] -= val;
}

void printArray(vector<ll>&A,vector<ll>&D{
    A[0] = D[0];
    cout<<A[0]<<" ";
    for(ll i=1;i<A.size();i++) {
        A[i] = D[i] + A[i - 1];
        cout << A[i] << " ";
    }
    cout<<endl;
}

int main(){
    vector<ll> A{10,5,20,40};
    vector<ll> D = initialize(A);

    Update(D,0,1,10);
    printArray(A,D);

    Update(D,1,3,20);
    Update(D,2,2,30);
    printArray(A,D);
}