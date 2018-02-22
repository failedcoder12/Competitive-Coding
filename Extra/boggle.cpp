#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

class node {
public:
    char data;
    hashmap h;
    bool isTerminal;
    node (char da){
        data = da;
        isTerminal = false;
    }
};

class trie {
public:
    node *root;

    trie() {
        root = new node('\0');
    }

    void addword(string word) {
        node *temp = root;
        for (int i = 0; word[i]; i++) {
            char ch = word[i];
            if (temp->h.count(ch) == 0) {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            } else {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }
    void searchword(node *n,char a[3][3],int i,int j,bool visited[3][3],string s){
        if(n->isTerminal){
            cout<<s<<endl;
        }
        if(isSafe(i,j,visited)){
            visited[i][j] = true;
            for(auto c:n->h){
                if(isSafe(i+1,j+1,visited) && a[i+1][j+1] == c.first){
                    searchword(c.second,a,i+1,j+1,visited,s+c.first);
                }
                if(isSafe(i,j+1,visited) && a[i][j+1] == c.first){
                    searchword(c.second,a,i,j+1,visited,s+c.first);
                }
                if(isSafe(i+1,j,visited) && a[i+1][j] == c.first){
                    searchword(c.second,a,i+1,j,visited,s+c.first);
                }
                if(isSafe(i-1,j-1,visited) && a[i-1][j-1] == c.first){
                    searchword(c.second,a,i-1,j-1,visited,s+c.first);
                }
                if(isSafe(i,j-1,visited) && a[i][j-1] == c.first){
                    searchword(c.second,a,i,j-1,visited,s+c.first);
                }
                if(isSafe(i-1,j,visited) && a[i-1][j] == c.first){
                    searchword(c.second,a,i-1,j,visited,s+c.first);
                }
                if(isSafe(i+1,j-1,visited) && a[i+1][j-1] == c.first){
                    searchword(c.second,a,i+1,j-1,visited,s+c.first);
                }
                if(isSafe(i-1,j+1,visited) && a[i-1][j+1] == c.first){
                    searchword(c.second,a,i-1,j+1,visited,s+c.first);
                }
            }
            visited[i][j] = false;
        }
    }

    bool isSafe(int i,int j,bool visited[3][3]){
        return (i>=0 && i<3 && j>=0 && j<3 && !visited[i][j]);
    }

    void printallpossible(char a[3][3]){
        bool visited[3][3];
        memset(visited, false, sizeof(visited));
        node *temp = root;
        string s = "";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(temp->h.count(a[i][j])){
                    searchword(temp->h[a[i][j]],a,i,j,visited,s+a[i][j]);
                }
            }
        }
    }
};
int main(){
    trie t;
    string a[] = {"GEEKS", "FOR", "QUIZ", "GEE"};
    for(int i=0;i<4;i++){
        t.addword(a[i]);
    }
    char arr[3][3] = {{'G','I','Z'},
                      {'U','E','K'},
                      {'Q','S','E'}};
    t.printallpossible(arr);
}
