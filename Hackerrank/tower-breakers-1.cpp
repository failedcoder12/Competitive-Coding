// https://www.hackerrank.com/challenges/tower-breakers-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    while(n--){
        long long int n,m;
        cin>>n>>m;
        if(n%2==0||m==1)
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}