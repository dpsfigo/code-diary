//
// Created by yuan Qing on 2024/10/29.
//
/***
 * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 * ***/
 /***
  * 把所有孩子的糖果数初始化为 1;
  * 先从左往右遍历一遍，如果右边孩子 的评分比左边的高，则右边孩子的糖果数更新为左边孩子的糖果数加 1;
  * 再从右往左遍历一遍， 如果左边孩子的评分比右边的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，则左边孩 子的糖果数更新为右边孩子的糖果数加 1。
  * 通过这两次遍历，分配的糖果就可以满足题目要求了。 这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系。

  * ***/
#include <iostream>
#include <vector>
#include <numeric>

class Solution{
public:
    int candy(std::vector<int> &ratings){
        int n = ratings.size();
        std::vector<int> candies(n,1);
        for (int i = 1; i < n; ++i) {
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1] +1;
            }
        }
        for (int i = n-1; i >0 ; --i) {
            if(ratings[i]<ratings[i-1]){
                //如果经过一次遍历，左边比右边大了，这时候可能右边+1也没有左边大，所以取两者的最大值
                candies[i-1] = std::max(candies[i-1],candies[i]+1);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};


//int main(){
//    Solution* sol = new Solution();
//    std::vector<int> ratings = {1,3,4,5,2};
//    int ret;
//    ret = sol->candy(ratings);
//    std::cout<<ret<<std::endl;
//
//    return 0;
//}