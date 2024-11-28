//
// Created by dps_figo on 2024/11/13.
//
/***
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
***/
#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    void merge(vector<int>& nums1,int m, vector<int>& nums2, int n){
        int p1 = m-1, p2 = n-1;
        int pos = m+n-1;
        int cur = 0;
        while(p1 >= 0 || p2 >=0){
            if (p1 == -1){
                cur = nums2[p2--];
            } else if (p2 == -1){
                cur = nums1[p1--];
            } else if (nums1[p1]>nums2[p2]){
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[pos--]=cur;
        }
    }

};

//int main(){
//    Solution* sol = new Solution();
//    vector<int> numbers1 = {1,2,3,0,0,0};
//    vector<int> numbers2 = {2,5,6};
//    vector<int> ret;
//    int m=3,n=3;
//    sol->merge(numbers1,m,numbers2,n);
//    for (int i = 0; i < numbers1.size(); ++i) {
//        cout<<numbers1[i]<<endl;
//    }
//
//    return 0;
//}