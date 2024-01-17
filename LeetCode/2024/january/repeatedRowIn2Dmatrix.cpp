#include <bits/stdc++.h>
using namespace std;
class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int R, int C) 
    { 
        // Your code here
        map<vector<int>,int>mp;
        vector<int>temp;
        vector<int> ans;
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                temp.push_back(matrix[i][j]);
            }
            if(mp.find(temp)!=mp.end()){
                ans.push_back(i);
            }else{
                mp[temp]=i;
            }
            temp.clear();
        }

        for(auto it:mp){
            for(auto ele:it.first){
                cout<<ele<<" ";
            }
            cout<<"->"<<it.second;
            cout<<endl;
        }
        return ans;
    } 
};
int main(){

    /*  matrix[][] = {{1, 0, 0},
                               {1, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}}; */
    vector<vector<int>> matrix = {{1, 0, 0},
                                  {1, 0, 0},
                                  {0, 0, 0},
                                  {0, 0, 0}};
    int R = 4;
    int C = 3;
    Solution obj;
    vector<int> ans = obj.repeatedRows(matrix, R, C);
    for(auto it:ans){
        cout<<it<<" ";
    }


    return 0;
}