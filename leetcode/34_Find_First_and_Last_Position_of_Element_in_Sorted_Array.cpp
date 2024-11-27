//
// Created by yuan Qing on 2024/11/27.
//
/***
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
***/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower){
        int l = 0, r = int(nums.size())-1,mid,ans;
        while (l <= r){
            mid = l + (r-l)/2;
            if (nums[mid] > target || (lower && nums[mid] >= target)){
                r = mid -1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()){
            return vector<int>{-1,-1};
        }
        int leftIdx = binarySearch(nums,target,true);
        int rightIdx = binarySearch(nums,target,false) -1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[rightIdx] == target && nums[leftIdx] == target){
            return vector<int>{leftIdx,rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ret;
    ret = sol->searchRange(nums,target);
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i]<<endl;
    }
    return 0;
}