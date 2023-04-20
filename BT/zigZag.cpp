#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
void levelOrderTraversal(node *root){
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();

            if(temp== NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
             }
             else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
             }
        }
}
void buildFromLevelOrder(node *root){
    queue<node*> q;
    cout<<"Level Order Rebuilt"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node* temp= q.front();
        q.pop();

        cout<<"Enter left child of "<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout<<"Enter right child of "<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->right = new node(data);
            q.push(temp->right);
        }
    }

}

vector<int> zigZagTraversal(node *root){

    vector<int> result;
    if(root==NULL){
        return result;
    }
    
    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();
        vector<int> ans(size);

        // level Process
        for(int i=0;i<size;i++){
            node* frintNode = q.front();
            q.pop();

            // normal insert of reverse 
            int index = leftToRight ? i : size-i-1;
            ans[index] = frintNode->data;

            if(frintNode->left){
                q.push(frintNode->left);
            }
            if(frintNode->right){
                q.push(frintNode->right);
            }
        }
        // direction change krni hai
        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }

    }
    return result;
}


void inorder(node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    // inorder(root);
    levelOrderTraversal(root);
    cout<<endl;
    vector<int> ans = zigZagTraversal(root);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}