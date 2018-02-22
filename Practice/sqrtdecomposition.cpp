#include<bits/stdc++.h>
using namespace std;

//Sqrt Decomposition

//Range Sum Query

int query(int *blocks,int *a,int L,int R,int rn){
	int ans = 0;

	//left part
	while(L<r && L!=0 L%rn !=0){
		ans+=a[L++];
	}

	//Middle Part
	while(L+rn<=R){
		int block_id = L/rn;
		ans+=blocks[block_id];
		L+=rn;
	}

	//Last Part
	while(L<=R){
		ans+=a[L++];
	}
	return ans;
}

void update(int *blocks,int *a,int i,int val,int rn){
	int block_id = i/rn;
	blocks[block_id] +=(val-a[i]);
	a[i] = val;
}

int main(){
	int a[] = {1,3,5,2,7,6,3,1,4,8};
	int n = sizeof(a)/sizeof(int);

	int rn = sqrt(n);
	int *blocks = new int[rn+1]{0};
	// Build a block Array
	int block_id = -1;

	for(int i=0;i<n;i++){
		if(i%rn == 0){
			block_id++;
		}
		blocks[block_id] += a[i];
	}
	//print block array
	for(int i=0;i<=rn;i++){
		cout<<blocks[i]<<",\n";
	}

	//Update
	update(blocks,a,2,15,rn);

	//Queries
	cout<<query(blocks,a,2,8,rn);
}