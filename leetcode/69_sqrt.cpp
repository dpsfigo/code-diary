//
// Created by yuan Qing on 2024/11/26.
//
/***
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
***/

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int l = 1,r = x, mid, div;
        while (l <= r){
            mid = l + (r-l)/2;
            div = x/mid;
            if (mid == div){
                return mid;
            }
            if (mid < div){
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        return r;
    }
};

int main(){
    Solution* sol = new Solution();
    int x = 8;
    int ret;
    ret = sol->mySqrt(x);
    std::cout<<ret<<std::endl;
    return 0;
}