#include<bits/stdc++.h>
using namespace std;

int pow(int x,int y){
	if(y==0){
		return 1;
	int temp = pow(x,y/2);
	if(y%2==0){
		return temp*temp;
	}else {
		return x*temp*temp;
	}
}}

float negapow(float x,int y){
	float temp;
	if(y==0)
		return 1;
	temp = negapow(x,y/2);
	if(y%2==0){
		return temp*temp;
	}else {
		if(y>0){
			return x*temp*temp;
		}else {
			return (temp*temp)/x;
		}
	}
}

int main(){
	cout<<pow(2,10)<<endl;
	cout<<negapow(2,-2)<<endl;
}