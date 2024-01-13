#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];

    bool containKey(int bit){
        return (links[bit]!=NULL);
    }

    void put(int bit,Node* node){
        links[bit]=node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
    
    void insert(int num){
        Node* node=root;

        for(int i=31; i>=0; i--){
            int bit=((num>>i)&1);
           if(!node->containKey(bit)){
                node->put(bit,new Node());
           }
            node=node->get(bit);
        }
    }
    
    int getMax(int num){
        int maxNum=0;
        Node* node=root;

        for(int i=31; i>=0; i--){
            int bit=((num>>i)&1);
           if(node->containKey(1-bit)){
                maxNum=maxNum|(1<<i);
                node=node->get(1-bit);
           }else{
               node=node->get(bit);
           }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.
    Trie trie;
    int maxi=0;
    for(auto it:arr1){
        trie.insert(it);
    }

    for(auto it:arr2){
        maxi=max(maxi, trie.getMax(it));
    }

    return maxi;

}

int main(){
//     1
// 7 7
// 6 6 0 6 8 5 6
// 1 7 1 7 8 0 2
// Sample Output 1:
// 15
      
      vector<int> arr1={6,6,0,6,8,5,6};
    vector<int> arr2={1,7,1,7,8,0,2};

        cout<<maxXOR(7,7,arr1,arr2);
}