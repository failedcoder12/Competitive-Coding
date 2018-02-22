#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class JOB {
public:
    char name;
    ll deadline;
    ll profit;
    JOB(char n,ll d,ll p){
        name = n;
        deadline = d;
        profit = p;
    }
};


bool compare(JOB a,JOB b){
    return (a.profit>b.profit);
}


int main(){

    ll n = 5;
    JOB J[5] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                 {'d', 1, 25}, {'e', 3, 15}};

    sort(J,J+n,compare);
    ll result[n];
    bool slot[n] = {false};
    for(ll i=0;i<n;i++){
        for(ll j = min(n,J[i].deadline)-1;j>=0;j--){
            if(!slot[j]){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for(ll i=0;i<n;i++){
        if(slot[i]){
            cout<<J[result[i]].name<<" ";
        }
    }
}