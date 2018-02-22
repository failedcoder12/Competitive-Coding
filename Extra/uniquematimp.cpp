#include<bits/stdc++.h>
using namespace std;

int mat[10][10];

void fillother(int i,int j,int n){
	int x=2;
	for(int k = i+1;k<n;k++){
		mat[k][j] = x++; 
	}
	for(int k = 0;k<i;k++){
		mat[k][j] = x++;	
	}
}

void constructmat(int n){
	int left = n-1;
	int right = 0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			mat[i][left] = 1;
			fillother(i,left,n);
			left--;
		}else {
			mat[i][right] = 1;
			fillother(i,right,n);
			right++;		
		}
	}
}

int main(){
	int n=5;
	constructmat(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}