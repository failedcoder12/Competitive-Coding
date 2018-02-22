#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template <typename T>
class Graph {

    unordered_map<T ,list<pair<T,ll>>> m;

public:
    void addedge(T u,T v,ll distance,bool bidir = true){
        m[u].push_back(make_pair(v,distance));
        if(bidir){
            m[v].push_back(make_pair(u,distance));
        }
    }

    void printedge(){
        for(auto j:m){
            cout<<j.first<<"->";
            for(auto l:j.second){
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }

    void dijiktra(T source){
        unordered_map<T,ll> dist;
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        set<pair<ll,T>>s;
        dist[source] = 0;
        s.insert(make_pair(dist[source],source));
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            ll nodedist = p.first;
            s.erase(s.begin());
            for(auto childpair:m[node]){
                if(nodedist + childpair.second < dist[childpair.first]){
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodedist + childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }

};

int main() {
    Graph<string> g;
    g.addedge("Amritsar","Delhi",1);
    g.addedge("Amritsar","Jaipur",4);
    g.addedge("Jaipur","Delhi",2);
    g.addedge("Jaipur","Mumbai",8);
    g.addedge("Bhopal","Agra",2);
    g.addedge("Mumbai","Bhopal",3);
    g.addedge("Agra","Delhi",1);
    g.dijiktra("Amritsar");
}

