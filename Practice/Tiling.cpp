#include <bits/stdc++.h>
using namespace std;

int countt = 10;

bool defectivecheck(int xdef,int ydef,int xs,int xe,int ys,int ye){
    if((xdef<=xe && xdef>=xs)&&(ydef<=ye&&ydef>=ys))
        return true;
    return false;
}

void tiling(int a[][8],int xdef,int ydef,int xs = 0,int xe = 7,int ys = 0,int ye = 7){
    int size = xe-xs + 1;
    if(size == 2){
        for(int i=xs;i<=xe;i++){
            for(int j=ys;j<=ye;j++){
                if(!(i==xdef&&j==ydef)){
                    a[i][j] = countt;
                }
            }
        }
        countt++;
        return;
    }

    int xmid = (xe+xs)/2;
    int ymid = (ye+ys)/2;

    pair<int,int> p1;
    pair<int,int> p2;
    pair<int,int> p3;
    pair<int,int> p4;

    // int cx = countt;
    if(defectivecheck(xdef,ydef,xs,xmid,ys,ymid)){
        tiling(a,xdef,ydef,xs,xmid,ys,ymid);
        p1 = make_pair(xdef,ydef);
    }else {
        tiling(a,xmid,ymid,xs,xmid,ys,ymid);
        // a[xmid][ymid] = cx;
        p1 = make_pair(xmid,ymid);
    }
    if(defectivecheck(xdef,ydef,xmid+1,xe,ymid+1,ye)){
        tiling(a,xdef,ydef,xmid+1,xe,ymid+1,ye);
        p2 = make_pair(xdef,ydef);
    }else {
        tiling(a,xmid+1,ymid+1,xmid+1,xe,ymid+1,ye);
        // a[xmid][ymid] = cx;
        p2 = make_pair(xmid+1,ymid+1);
    }
    if(defectivecheck(xdef,ydef,xs,xmid,ymid+1,ye)){
        tiling(a,xdef,ydef,xs,xmid,ymid+1,ye);
        p3 = make_pair(xdef,ydef);
    }else {
        tiling(a,xmid,ymid+1,xs,xmid,ymid+1,ye);
        // a[xmid][ymid] = cx;
        p3 = make_pair(xmid,ymid+1);
    }
    if(defectivecheck(xdef,ydef,xmid+1,xe,ys,ymid)){
        tiling(a,xdef,ydef,xmid+1,xe,ys,ymid);
        p4 = make_pair(xdef,ydef);
    }else {
        tiling(a,xmid+1,ymid,xmid+1,xe,ys,ymid);
        // a[xmid][ymid] = cx;
        p4 = make_pair(xmid+1,ymid);
    }
    if(!defectivecheck(xdef,ydef,xs,xmid,ys,ymid)){
        a[p1.first][p1.second] = countt;
    }
    if(!defectivecheck(xdef,ydef,xmid+1,xe,ymid+1,ye)){
        a[p2.first][p2.second] = countt;}
    if(!defectivecheck(xdef,ydef,xs,xmid,ymid+1,ye)){
        a[p3.first][p3.second] = countt;}
    if(!defectivecheck(xdef,ydef,xmid+1,xe,ys,ymid)){
        a[p4.first][p4.second] = countt;
    }
    // cout<<cx<<",";
    countt ++;
}

int main(){
    int a[8][8] = {0};
    for(int i=0 ; i<=7 ; i++)
    {
        for(int j=0 ; j<=7 ; j++)
        {
            a[i][j] = 88;
        }

    }
    int x = 1;
    int y = 2;
    cout<<endl;
    tiling(a,x,y);
    cout<<endl;
    for(int i=0 ; i<=7 ; i++)
    {
        for(int j=0 ; j<=7 ; j++)
        {
            if(i==x&&j==y)
                cout<<"00 ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}