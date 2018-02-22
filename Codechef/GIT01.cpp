
//https://www.codechef.com/DEC17/problems/GIT01

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        int mat[r][c], x[r][c], y[r][c];
        char cc;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> cc;
                if (cc == 'R') {
                    mat[j][k] = 1;
                } else {
                    mat[j][k] = 0;
                }
            }
        }
 
        if(c%2!=0) {
            int q = 0;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    x[j][k] = q;
                    if (q == 0) q = 1;
                    else q = 0;
                }
            }
 
            q = 1;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    y[j][k] = q;
                    if (q == 0) q = 1;
                    else q = 0;
                }
            }
        } else {
            int q = 0,p=0;
            for (int j = 0; j < r; j++) {
                q=p;
                for (int k = 0; k < c; k++) {
                    x[j][k] = q;
                    if (q == 0) q = 1;
                    else q = 0;
                }
                if (p == 0) p = 1;
                else p = 0;
            }
 
            q = 1;p=1;
            for (int j = 0; j < r; j++) {
                q=p;
                for (int k = 0; k < c; k++) {
                    y[j][k] = q;
                    if (q == 0) q = 1;
                    else q = 0;
                }
                if (p == 0) p = 1;
                else p = 0;
            }
        }
        int c1=0;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if(mat[j][k]==1&&x[j][k]==0)
                    c1+=5;
                if(mat[j][k]==0&&x[j][k]==1)
                    c1+=3;
            }
        }
        int c2=0;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if(mat[j][k]==1&&y[j][k]==0)
                    c2+=5;
                if(mat[j][k]==0&&y[j][k]==1)
                    c2+=3;
            }
        }
        if(c1<c2)
            cout<<c1<<endl;
        else
            cout<<c2<<endl;
 
    }
} 