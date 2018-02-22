#include<bits/stdc++.h>
using namespace std;

class process{
public:
    int id;
    int arrivaltime;
    int bursttime;
    int starttime;
    int priority;
    int finishingtime;
    int waitingtime;
    int turnaroundtime;
};


int main(){

    int n;
    cout<<"Enter number of process"<<endl;
    cin>>n;
    process p[n];
    for(int i=0;i<n;i++){
        cout<<"For Process "<<i+1<<endl;
        cout<<"Enter arrival time : ";
        cin>>p[i].arrivaltime;
        cout<<"Enter burst time : ";
        cin>>p[i].bursttime;
        cout<<"Enter Priority : ";
        cin>>p[i].priority;
        p[i].id = i+1;
    }
         for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(p[i].arrivaltime > p[j].arrivaltime){
                        process temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                    }
                }
            }    int k=0;
    int time = 0;
    while(k<n){
        if(time < p[k].arrivaltime){
            time++;
             cout<<time<<endl;
        }else {
        for(int i=k;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(p[i].arrivaltime <= time && p[j].arrivaltime<=time)
                    if(p[i].priority > p[j].priority){
                        process temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                    }
                }
            }        
            p[k].starttime = time;
            time = time + p[k].bursttime;
            p[k].finishingtime = time;
             cout<<time<<endl;
            k++;
        }
    }
    for(int i=0;i<n;i++){
        p[i].waitingtime = p[i].starttime - p[i].arrivaltime;
        p[i].turnaroundtime = p[i].finishingtime - p[i].arrivaltime;
    }
    cout<<"Process ID   "<<"Arrival TIme    "<<"Burst Time    "<<"Priority      "<<"Waititng Time    "<<"TurnAroundTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].id<<"\t\t"<<p[i].arrivaltime<<"\t\t"<<p[i].bursttime<<"\t\t"<<p[i].priority<<"\t\t"<<p[i].waitingtime<<"\t\t"<<p[i].turnaroundtime<<endl;
    }

}