#include<iostream>
using namespace std;

class perceptronand {
public:
float w1,w2;
float threshold;
float correctionper;
    perceptronand(){
        w1 = 65;
        w2 = -95;
        threshold = -90;
        correctionper = 0.1;
    }
  
    int checkans(int a1,int a2){
        if((a1*w1 + a2*w2)>=threshold){
            return 1;
        }else return 0;
    }  
    int outputcheck(int a1,int a2,int o){
        if(checkans(a1,a2)==1 && o==1){
            return 1;
        }else if(checkans(a1,a2)==0 && o==0){
            return 1;
        }
    return 0;
    }
    void changevalues(int a1,int a2,int o,int original){
        if(!outputcheck(a1,a2,o)){
            w1 = w1 + correctionper*(o-original)*a1;
            w2 = w2 + correctionper*(o-original)*a2;
            threshold = threshold - correctionper*(o-original);
        }
    }

};

int main(){
perceptronand p;
int a1,a2,o,originalo;
    cout<<p.checkans(0,0)<<endl;
    cout<<p.checkans(0,1)<<endl;
    cout<<p.checkans(1,0)<<endl;
    cout<<p.checkans(1,1)<<endl;
int i=0;
while(1){
   cout<<i++<<" ";
    if(p.outputcheck(0,0,0)&&p.outputcheck(0,1,1)&&p.outputcheck(1,0,1)&&p.outputcheck(1,1,1))
        break;
    // if(i==10000)
    //     break;
    p.changevalues(0,0,0,p.checkans(0,0));
    p.changevalues(0,1,1,p.checkans(0,1));
    p.changevalues(1,0,1,p.checkans(1,0));
    p.changevalues(1,1,1,p.checkans(1,1));
        cout<<p.w1<<" "<<p.w2<<" "<<p.threshold<<" "<<endl;
        cout<<p.checkans(0,0)<<" ";
    cout<<p.checkans(0,1)<<" ";
    cout<<p.checkans(1,0)<<" ";
    cout<<p.checkans(1,1)<<" ";
}cout<<endl;    cout<<p.checkans(0,0)<<endl;
    cout<<p.checkans(0,1)<<endl;
    cout<<p.checkans(1,0)<<endl;
    cout<<p.checkans(1,1)<<endl;
}