#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    // int n=s.size();
    // set<string> st;
    // string str="";

    // for(int i=0; i<n; i++){
    //     str="";
    //     for(int j=i; j<n; j++){
    //         str+=s[j];
    //         st.insert(str);
    //     }
    // }
   
    // return st.size()+1;

    Node* root= new Node();
    int cnt=0;

    for(int i=0; i<s.size(); i++){
        Node* node=root;
        for(int j=i; j<s.size(); j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;


}

int main(){
    string s;
    cin>>s;
    cout<<countDistinctSubstrings(s);
    return 0;
    
}