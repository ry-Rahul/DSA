#include <bits/stdc++.h>
using namespace std;

void nextAlphabet(char arr[],int size,char target) {

        int start=0,mid;
        int end = size -1;
        char next;

        while (start <= end) {
            mid = start + (end - start)/2;

            if(arr[mid] == target){
                start = mid +1;
            }
            else if(arr[mid] > target){
                next = arr[mid];
                end = mid -1;
                }
            else
                start = mid +1;

        }


        if(mid == size-1)
            cout<<" Not found"<<endl;
        else
            cout<<next<<endl;
        

}

int main(){
    
        char arr[] = {'a','c','f','h','k','l','m','n','p'};
        int size = sizeof(arr)/sizeof(arr[0]);
        char target = 'p';

        cout<<endl<<"Next alphabet:";
        nextAlphabet(arr,size,target);

        // cout<<returnChar()<<endl;

  return 0;
}