#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*  int perator(int a,int b,string token){
         if(token=="+"){
             return a+b;
         }
         if(token=="*"){
             return (long)a*(long)b;
         }
         if(token=="-"){
             return a-b;
         }
         if(token=="/"){
             return a/b;
         }
         return -1;
     } */
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"*", [](int a, int b)
             { return (long)a * (long)b; }},
            {"/", [](int a, int b)
             { return a / b; }}};

        for (auto &token : tokens)
        {

            if (token == "+" || token == "-" || token == "/" || token == "*")
            {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                // int result = perator(a,b,token);
                int result = mp[token](a, b);

                st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
int main()
{

    Solution obj;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << obj.evalRPN(tokens);
    cout << endl;

    return 0;
}