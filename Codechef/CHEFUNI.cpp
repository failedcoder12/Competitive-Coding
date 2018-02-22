
// https://www.codechef.com/DEC17/problems/CHEFUNI

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
 
// ll cost1(ll x,ll y,ll z,ll a,ll b,ll c){
//     ll cost=0;
//     return (x+y+z)*a;
// }
 
// ll cost2(ll x,ll y,ll z,ll a,ll b,ll c){
//     ll cost = 0;
    
//     if(x>y){
//         ll t=x;
//         x=y;
//         y=t;
 
//     }
//     if(y>z){
//         ll t=y;
//         y=z;
//         z=t;
//     }
//     if(x>y){
//         ll t=x;
//         x=y;
//         y=t;
//     }
//     if(x+y<=z){
//         cost+=(x+y)*b;
//         z=z-(x+y);
//         x = 0;
//         y=0;
//         cost+=cost1(x,y,z,a,b,c);
//         return cost;
//     }else {
//         cost+=(y-x)*b;
//         z = z-(y-x);
//         y = y-(y-x);
//     }
//     if(x+y<=z){
//         cost+=(x+y)*b;
//         z=z-(x+y);
//         x = 0;
//         y=0;
//         cost+=cost1(x,y,z,a,b,c);
//         return cost;
//     }else {
//         if((x+y+z)%2!=0){
//         cost+=(z+x+y)/2*b-b;
//         x=y=z=1;}
//         else {
//             cost += (z+x+y)/2*b;
//             return cost;
//         }
//     }
//     if(x==y&&y==z&&(x>2)){
//         cost+=(x-2)/2*3;
//         if(x%2==0){
//             x=y=z=2;
//         }else {
//             x=y=z=1;
//         }
//     }
//     if(x==2&&y==2&&z==2){
//         return cost+3*b;
//     }
 
//     if(x!=0&&y!=0&&z!=0){
//         cost += min(a+b,min(c,3*a));
//         x=x-1;
//         y=y-1;
//         z=z-1;}
//     cost+=cost1(x,y,z,a,b,c);
//     return cost;
// }
 
// ll cost3(ll x,ll y,ll z,ll a,ll b,ll c){
//     ll p =min(x,min(y,z));
//     ll cost=0;
//     cost+=p*c;
//     x=x-p;
//     y=y-p;
//     z=z-p;
//     cost+=min(cost2(x,y,z,a,b,c),cost1(x,y,z,a,b,c));
//     return cost;
// }
 
// int main() {
 
//     ll t;
//     cin >> t;
//     for (ll i = 0; i < t; i++) {
//         ll a, b, c, x, y, z;
//         cin >> x >> y >> z >> a >> b >> c;
//         cout<<min(cost1(x,y,z,a,b,c),min(cost2(x,y,z,a,b,c),cost3(x,y,z,a,b,c)))<<endl;
//     }
// } 

// After Seeing Solution

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y,z,a,b,c;
        cin>>x>>y>>z>>a>>b>>c;
        b = min(b,a+a);
        c=min(a+b,c);
        if(x>y)
            swap(x,y);
        if(x>z)
            swap(x,z);
        if(y>z)
            swap(y,z);
        ll ans = 0;
        if(a+c<=b+b){
            ans = a*(z-y) + b*(y-x) + c*x;
        }else if(2*c<=3*b){
            if(z<=x+y) ans = b*(2*z-x-y) + x*(x+y-z);
            else ans = b*(x+y)+a*(z-x-y);
        }else {
            if(z<=x+y) ans = b*(x+y+z)/2 + a*(x+y+z&1);
            else ans=b*(x+y)+a*(z-x-y);
            if((x+y+z)%2==1&&z<=x+y) ans = c+b*((x+y+z)/2-1);
        }
        cout<<ans<<endl;
    }
}