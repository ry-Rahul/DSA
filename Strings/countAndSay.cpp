#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1){
            return "1";
        }

        string say = countAndSay(n-1);
        string ans = "";
        int count = 1;
        for(int i=1; i<say.length(); i++){
            
        }
        

    }
};


int main()
{

    /*
    Input: n = 4
  Output: "1211"
  Explanation:
  countAndSay(1) = "1"
  countAndSay(2) = say "1" = one 1 = "11"
  countAndSay(3) = say "11" = two 1's = "21"
  countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
    */

    int n = 5;
    Solution s;
    cout << s.countAndSay(n) << endl;

    return 0;
}