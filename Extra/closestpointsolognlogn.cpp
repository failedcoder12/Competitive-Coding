#include<bits/stdc++.h>
using namespace std;

class point {
public:
    int x;
    int y;
};

int compareX(const void* a,const void* b){
    point *p1 = (point *)a ;point *p2 = (point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a,const void* b){
    point *p1 = (point *)a ;point *p2 = (point *)b;
    return (p1->y - p2->y);
}
float distance(point p1,point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteforce(point p[],int n){
    float mini = FLT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(distance(p[i],p[j])<mini){
                mini = distance(p[i],p[j]);
            }
        }
    }
    return mini;
}

float min(float x,float y){
    if(x>y){
        return y;
    }
    return  x;
}

float stripclosest(point strip[],int size,float d){
    float mini = d;
    qsort(strip,size,sizeof(point),compareX);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size && (strip[j].y - strip[i].y) < mini;j++){
            if(distance(strip[i],strip[j])<mini){
                mini = distance(strip[i],strip[j]);
            }
        }
    }
    return mini;
}

float closesthelper(point p[],int n){
    if(n<=3){
        return bruteforce(p,n);
    }
    int mid = n/2;
    point midpoint = p[mid];
    float dr = closesthelper(p,mid);
    float dl = closesthelper(p+mid,n-mid);
    float d = min(dr,dl);
    point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(p[i].x-midpoint.x)<d){
            strip[j++] = p[i];
        }
    }
    return min(d,stripclosest(strip,j,d));
}

float closest(point p[],int n){
    qsort(p,n, sizeof(point),compareX);
    return closesthelper(p,n);
}

int main(){
    point p[] = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    int n = sizeof(p)/sizeof(p[0]);
    cout<<"Smallest Distance is : "<<closest(p,n)<<endl;
}