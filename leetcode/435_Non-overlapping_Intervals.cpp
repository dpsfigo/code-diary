//
// Created by dps_figo on 2024/11/12.
//
/***
 * Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 * ***/
/***
 * 求最少的移除区间个数，等价于尽量多保留不重叠的区间。
 * 在选择要保留区间时，区间的结 尾十分重要:选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。
 * 因 此，我们采取的贪心策略为，优先保留结尾小且不相交的区间。
具体实现方法为，先把区间按照结尾的大小进行增序排序(利用 lambda 函数)，每次选择结 尾最小且和前一个选择的区间不重叠的区间。
 * ***/

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){return a[1]<b[1];});
        int removed = 0, pre_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0]<pre_end){
                ++removed;
            } else{
                pre_end = intervals[i][1];
            }
        }
        return removed;
    }
};

//int main(){
//    Solution *sol = new Solution();
//    vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
//    int ret;
//    ret = sol->eraseOverlapIntervals(intervals);
//    cout<<ret<<endl;
//    return 0;
//}