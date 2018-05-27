// https://hack.codingblocks.com/contests/c/446/870

// Distance: The distance between two points in a grid based on a strictly horizontal and/or vertical path (i.e along the grid lines), as opposed to the Manhattan Distance or Diagonal Distance.

// The Manhattan Distance is the simple sum of the horizontal and vertical components, where as the Diagonal Distance might be computed by applying the Pythagorean Theorem.

// Problem Statements: A robot is moving on co-ordinate axis. Time taken to move from one point to another point is equal to the Manhattan Distance.

// Ex. Time taken to move from point ( x1 , y1) to ( x2 , y2) is |x1 - x2| + |y1 - y2| where | a | is equal to modulus function of a.

// Starting Point (S) and Ending Point (E) of the robot is fixed. There are n wormhole like pipelines also on the coordinate axis. Time taken to move from one point to another point of each pipeline is given.

// Robot can use those pipelines to move from statring point to ending point. Can you help to find the minimum time required during traversal.
// Input Format:

// The first line contains T, the number of test cases.

// The description of T test cases follows.

// The first line of each test case contains integer n which represents the number of pipelines.

// The next line contains four space seperated integer. The first two integer is the x and y coordinate of starting point and last two integer is the x and y coordinate of the ending points. The next n lines contains 5 space-separated character x1 , y1, x2 , y2, t . The first four integers are the x and y co-ordinate of terminal of the pipelines and 5 th integer is time to cross that pipelines .
// Constraints:

// 1 <= T <= 30
// 0 <= n <= 5
// 1 <=  x,y <= 2000

// Output Format:

// For each test case you have to print the output in this format (#Test Case Number : minimum time taken by robot to traverse from begining to ending point.)
// Sample Input:

// 3
// 0
// 20 20 100 100
// 1
// 20 20 100 100
// 25 25 30 30 5
// 3
// 20 20 100 100
// 35 35 50 50 0
// 30 30 25 25 0
// 40 40 60 60 100

// Sample Output:

// #1 : 160
// #2 : 155
// #3 : 120

// Explanation:

// For test case 1: time = |20-100| + |20-100| = 160

// For test case 2: Robot use pipeline => (20,20) --> (25, 25) -->(30,30) --> (100,100) , Total time = |20-25| +|20-25| + 5 + |30-100|+|30-100| = 155


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f3f3f3fLL

ll result;

void find_min(vector<ll> s,vector<ll> d,vector<vector<ll>> h,vector<bool> done,ll n,bool check,ll a,ll time){
    if(check){
        time += abs(s[0]-d[0]) + abs(s[1] - d[1]);
        result = min(result,time);
        return;
    }
    if(a == n){
        time += abs(s[0]-d[0]) + abs(s[1] - d[1]);
        result = min(result,time);
        return;
    }
    for(ll i=0;i<n;i++){
        if(!done[i]){
            {
                done[i] = true;
                ll t = abs(s[0] - h[i][0]) + abs(s[1] - h[i][1]);
                ll b = s[0];
                ll c = s[1];
                s[0] = h[i][2];
                s[1] = h[i][3];
                find_min(s, d, h, done, n, check, a + 1, time + t + h[i][4]);
                done[i] = false;
                s[0] = b;
                s[1] = c;
            }

            {
                done[i] = true;
                ll t = abs(s[0] - h[i][2]) + abs(s[1] - h[i][3]);
                ll b = s[0];
                ll c = s[1];
                s[0] = h[i][0];
                s[1] = h[i][1];
                find_min(s, d, h, done, n, check, a + 1, time + t + h[i][4]);
                done[i] = false;
                s[0] = b;
                s[1] = c;
            }
        }
    }
    find_min(s,d,h,done,n,!check,a+1,time);
}

int main(){
    ll tt;
    cin>>tt;
    for(ll t=1;t<=tt;t++){
        result = INT_MAX;
        ll n;
        cin>>n;
        vector<ll> s(2),d(2);
        cin>>s[0]>>s[1]>>d[0]>>d[1];
        vector<vector<ll>> h(n);
        vector<bool> done(n);
        for(ll i=0;i<n;i++){
            ll x1,x2,x3,x4,x5;
            cin>>x1>>x2>>x3>>x4>>x5;
            h[i].push_back(x1);
            h[i].push_back(x2);
            h[i].push_back(x3);
            h[i].push_back(x4);
            h[i].push_back(x5);
            done[i] = false;
        }
        
        find_min(s,d,h,done,n,false,0,0);
        cout<<"#"<<t<<" : "<<result<<endl;
    }
}