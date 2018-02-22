
// https://www.hackerrank.com/challenges/game-of-stones-1/

#include<bits/stdc++.h>
using namespace std;
    int main(){
        int n;
        cin>>n;
        while(n--){
            int a;
            cin>>a;
            if((a)%7==0||a==0||a==1||(a-1)%7==0)
                cout<<"Second"<<endl;
            else
                cout<<"First"<<endl;
        }
}