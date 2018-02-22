#include <bits/stdc++.h>
using namespace std;

int equallength(string &a,string &b){
    int a1 = a.length();
    int b1 = b.length();

    if(a1<b1){
        for(int i=0;i<b1-a1;i++){
            a = '0' + a;
        }
        return b1;
    }

    if(b1<a1){
        for(int i=0;i<a1-b1;i++){
            b = '0' + b;
        }
    }
    return a1;
}

string add(string a,string b){
    string c;
    int l = equallength(a,b);
    int carry = 0;
    for(int i=l-1;i>=0;i--) {
        int f = a[i] - '0';
        int s = a[i] - '0';

        int sum = (f^s^carry) +'0';

        c = (char)sum + c;
        carry = (f&s)|(s&carry)|(f&carry);
    }
    if(carry) {
        c = '1' + c;
    }
    return c;
}

int fastmultiply(string a,string b){
    int n = equallength(a,b);
    if(n==0){
        return 0;
    }else if(n==1){
        return (a[0] - '0')*(b[0]-'0');
    }

    int firsthalf = n/2;
    int secondhalf = n-firsthalf;
    cout<<n;
    string aleft = a.substr(0,firsthalf);
    string aright = a.substr(firsthalf,secondhalf);
    string bleft = b.substr(0,firsthalf);
    string bright = b.substr(firsthalf,secondhalf);
    long int p1 = fastmultiply(aleft,bleft);
    long int p2 = fastmultiply(aright,bright);
    long int p3 = fastmultiply(add(aleft,aright),add(bleft,bright));

    return (p1*(1<<(2*secondhalf))+(p3-p1-p2)*(1<<secondhalf) + p2);
}

int main(){
    cout<<fastmultiply("10","11")<<endl;
}