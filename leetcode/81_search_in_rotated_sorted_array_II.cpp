//
// Created by dps_figo on 2024/11/28.
//
/***
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
***/
/***
 *即使数组被旋转过，我们仍然可以利用这个数组的递增性，使用二分查找。
 * 对于当前的中点， 如果它指向的值小于等于右端，那么说明右区间是排好序的;
 * 反之，那么说明左区间是排好序的。
 * 如果目标值位于排好序的区间内，我们可以对这个区间继续二分查找;
 * 反之，我们对于另一半区 间继续二分查找。本题我们采用左闭右闭的写法
 * ***/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1,mid;
        while (l <= r){
            mid = l + (r-l)/2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[l]){
                ++l;
            } else if (nums[mid] == nums[r]){
                --r;
            } else if (nums[mid] < nums[r]){
                //右区间递增
                if (target >= nums[mid] && target <= nums[r]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target < nums[mid] && target >= nums[l]){
                    r = mid - 1;
                } else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    bool ret;
    ret = sol->search(nums,target);
    cout<<ret;
    return 0;
}