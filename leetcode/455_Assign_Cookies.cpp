//
// Created by dpsfigo on 2024/10/24.
//

/***
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.



Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
        You need to output 2.

Constraints:

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
***/

/***
方法：1，先对两个数组排序
    2，再遍历两个数组，遍历的过程中，分别比较两个数组，如果饼干满足孩子，两个都移动，如果饼干不满足孩子，移动饼干，找下一个满足的饼干。
    已经排好序了，当前饼干不满足，那也满足不了下一个孩子。
    3，结束条件：孩子或者饼干都遍历完了
时间复杂度：
 O(mlogm + nlogn)
 * ***/
#include <iostream>
#include <vector>

class solution{
public:
    int findContentChildred(std::vector<int> &g, std::vector<int> &s){
        std::sort(g.begin(), g.end());
        std::sort(s.begin(),s.end());
        int child_i = 0, cookie_i = 0;
        int child_n = g.size(), cookie_n = s.size();
        while (child_i < child_n && cookie_i < cookie_n){
            if (g[child_i] <= s[cookie_i]){
                ++child_i;
            }
            ++cookie_i;
        }
        return child_i;

    }
};

//int main(){
//    std::vector<int> childrens = {1, 2, 3};
//    std::vector<int> cookies = {1, 1};
//    solution *sol = new solution();
//    int ret;
//    ret = sol->findContentChildred(childrens,cookies);
//
//    std::cout<<ret<<"done"<<std::endl;
//    return 0;
//}