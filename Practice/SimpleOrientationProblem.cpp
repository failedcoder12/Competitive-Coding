#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x,y;
};

int findorientation(Point a,Point b,Point c){
	return (b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x);
}

int main(){

	Point a = {0,0},b = {4,4},c = {1,2};
	int o = findorientation(a,b,c);
	if(o == 0){
		cout<<"Collinear";
	}else if(o > 0){
		cout<<"Clockwise";
	}else {
		cout<<"Counter-Clockwise";
	}

}