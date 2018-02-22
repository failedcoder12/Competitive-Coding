#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll inf = INT_MAX;
    ll n = 4;
    ll graph[n][n] = {
            {0,3,6,15},
            {inf,0,-2,inf},
            {inf,inf,0,2},
            {1,inf,inf,0}
    };

    ll distance[n][n];
    ll path[n][n];
//Making new matrix which show diatance and parent
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            distance[i][j] = graph[i][j];
            if(graph[i][j]!=inf && i!=j){
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
//Using Dp if distance from a point k is less than direct distance
    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(distance[i][k] == inf || distance[k][j] == inf){
                    continue;
                }
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
//Negative Cycle
    for(ll i=0;i<n;i++){
        if(distance[i][i] < 0){
            cout<<endl<<"Negative Cycle"<<endl;
        }
    }

    for(ll i=0;i<n;i++) {
        for (ll j = 0; j < n; j++) {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }

    ll from = 3,to = 2;

    if((from < 0)||(to < 0)||(from > n)||(to > n)){
        cout<<endl<<"No Path"<<endl;
        return 0;
    }
    cout<<"Actual Path between "<<from<<" to "<<to<<" is "<<endl;
    stack<ll> stack1;
    stack1.push(to);
    while(1){
        to = path[from][to];
        if(to == -1){
            break;
        }
        stack1.push(to);
        if(to == from){
            break;
        }
    }

    while(!stack1.empty()){
        cout<<stack1.top()<<" ";
        stack1.pop();
    }

}