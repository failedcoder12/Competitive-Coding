

//https://www.codechef.com/DEC17/problems/CPLAY


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    char cb[20];
    while(cin>>cb){
        int a=0,ba=5,bb=5;int i=0,y=1;
 
        for(i=0;i<10;i=i+2){
            ba--;
            int x=0,t=0;
            if(cb[i] == '1')
                x=1;
            if(cb[i+1]== '1')
                t=1;
            a = a + x-t;
            if(a == ba&&ba!=0){
                if(cb[i+2]=='1')
                {
                    printf("TEAM-A %d\n", i+3);
                    y=0;
                    break;
                }
            }
            else if(-1*a == ba&&ba!=0){
                if(cb[i+2]=='0')
                {
                    printf("TEAM-B %d\n", i+3);
                    y=0;
                    break;
                }
            }
            else if(a>ba){
                printf("TEAM-A %d\n", i+2);
                y=0;
                break;
            }
            else if(-1*a>ba){
                    printf("TEAM-B %d\n", i+2);
                y=0;
                break;
            }
        }
        if(y==0)
            continue;
        int x=0;
        for(i=10;i<strlen(cb);i=i+2){
            if(cb[i]=='1'&&cb[i+1]=='0'){
                printf("TEAM-A %d\n", i+2);x=1;break;
            } else if(cb[i]=='0'&&cb[i+1]=='1'){
                printf("TEAM-B %d\n", i+2);x=1;break;
            }
        }
        if(x==1)
            continue;
        printf("TIE\n");
    }
} 
