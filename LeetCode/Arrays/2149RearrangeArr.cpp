#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr);


vector<int> rearrangeArray(vector<int>& nums) {
         vector<int> arr1;
         vector<int> arr2;

         for(int i =0; i<nums.size(); i++){
             if(nums[i]<0)
                arr1.push_back(nums[i]);
             else
                arr2.push_back(nums[i]);
         }

            int i=0,j=0,k=0;
            while(i<arr1.size() && j<arr2.size()){
                nums[k++] = arr2[j++];
                nums[k++] = arr1[i++];
            }
       return nums;
}

vector<int> rearrangeArray2(vector<int>& nums){

    int i=0,j=nums.size()-1;
    while(i<j){
        if(nums[i]<0)
            i++;
        else if(nums[j]>0)
            j--;
        else{
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    return nums;
}

void printArr(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){ 

    vector<int> arr = {3,1,-2,-5,2,-4};
    printArr(arr);
    vector<int> res = rearrangeArray(arr);
    printArr(res);

    vector<int> arr2 = {3,1,-2,-5,2,-4};
    printArr(arr2);
  

  return 0;
}