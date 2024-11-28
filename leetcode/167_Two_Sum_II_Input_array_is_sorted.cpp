//
// Created by dps_figo on 2024/11/13.
//
/***
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.



Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 * ***/
 /***
  * 因为数组已经排好序，我们可以采用方向相反的双指针来寻找这两个数字，一个初始指向最 小的元素，即数组最左边，向右遍历;一个初始指向最大的元素，即数组最右边，向左遍历。
如果两个指针指向元素的和等于给定值，那么它们就是我们要的结果。
  如果两个指针指向元 素的和小于给定值，我们把左边的指针右移一位，使得当前的和增加一点。
  如果两个指针指向元 素的和大于给定值，我们把右边的指针左移一位，使得当前的和减少一点。
  * ***/

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int l = 0,r=numbers.size()-1,twoSum;
        while(l<r){
            twoSum = numbers[l] + numbers[r];
            if (twoSum == target){
                break;
            }
            if (twoSum < target){
                ++l;
            } else{
                --r;
            }
        }
        return vector<int>{l+1,r+1};
    }

};

//int main(){
//    Solution* sol = new Solution();
//    vector<int> numbers = {2,3,4};
//    int target = 6;
//    vector<int> ret;
//    ret = sol->twoSum(numbers,target);
//    for(int i = 0; i < ret.size(); ++i) {
//        std::cout << ret[i] << endl;
//    }
//    return 0;
//}
