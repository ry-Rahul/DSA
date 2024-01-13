#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};

class Trie{
    private:
        Node* root;

    public:

        Trie(){
            root=new Node();
        }

        //Insert into trie
        void insert(string word){
            Node* node=root;
            for(int i=0; i<word.size(); i++){
                if(!node->containKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }

        bool checkAllPrefixExists(string word){
            Node *node=root;
            bool flag=true;
            for(int i=0; i<word.size(); i++){
                if(node->containKey(word[i])){
                    node=node->get(word[i]);
                    flag=flag & node->isEnd();
                }else{
                    return false;
                }
            }
            return flag;

        }

};

string completeString(int n, vector<string> &a){
    // Write your code here.

    Trie trie;

    for(auto it:a){
        trie.insert(it);
    }

    string longest="";

    for(auto it:a){
        if(trie.checkAllPrefixExists(it)){
            if(it.size()>longest.size()){
                longest=it;
            }else if(it.size()==longest.size() && it<longest){
                longest=it;
            }
        }
    }

    if(longest=="") return "None";
    return longest;
    // return longest=""?"None":longest;

}
int main(){
 
    vector<string> a={"abc","ab","abcd","abce"};
    cout<<completeString(4,a);
    return 0;
}