#include <bits/stdc++.h>
using namespace std;

int knapsack(int W,int wt[],int val[],int n){
    int Knap[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)
                Knap[i][j] = 0;
            else if(wt[i-1]<=j){
                Knap[i][j] = max(val[i-1]+Knap[i-1][j-wt[i-1]],Knap[i-1][j]);
            }else {
                Knap[i][j] = Knap[i-1][j];
            }
        }
    }
    return Knap[n][W];
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = 3;
    cout<<knapsack(W,wt,val,n);
}