#include <bits/stdc++.h>
using namespace std;

// find the square of two numbers 
int square(int a, int b){
    if (b == 0)
        return 0;
    if (b == 1)
        return a;
    int ans = a + square(a, b - 1);
    return ans;
}