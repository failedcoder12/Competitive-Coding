#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void printEgyptian(int n,int r){
    if(n==0||r==0){
        return;
    }
    int largestpossiblefraction = (ceil((float)r/(float)n));
    cout<<1<<"/"<<largestpossiblefraction<<" ";
    
    int n1 = n*largestpossiblefraction - r;
    int r1 = r*largestpossiblefraction;
    
    printEgyptian(n1,r1);
    
}

int main(){
    // 1/a = 1/(a+1) + 1/(a+1)(a)
    int n = 12;
    int r = 13;
    cout<<"Egyptian Fraction for "<<n<<"/"<<r<<" is \n";
    printEgyptian(2,4);
    
}