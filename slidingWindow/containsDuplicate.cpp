#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j] && abs(i - j) <= k)
            {
                return true;
            }
        }
    }

    return false;
}

// Approach 2
bool containsNearbyDuplicate2(vector<int> &nums, int k){

    int i=0;
    int j=0;
    int n = nums.size();

    unordered_set<int> s;

    while(j<n){
        
        if(abs(i-j)>k){
            s.erase(nums[i]);
            i++;
        }

            // if the element is already present in the set
            if(s.find(nums[j])!=s.end()){
                return true;
            }
            else{
                // insert the element in the set
                s.insert(nums[j]);
            }


        

        j++;
    }

    return false;
}
int main()
{

    vector<int> arr = {1, 2,3,4,1,2,3,2};
    int k = 3;

    cout << containsNearbyDuplicate(arr, k) << endl;

    return 0;
}