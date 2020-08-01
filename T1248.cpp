/*******************************
 * LeetCode 第1248题：统计“优美子数组”
 * 给你一个整数数组 nums 和一个整数 k。
 * 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
 * 请返回这个数组中「优美子数组」的数目。
 * Date：2020-08-01
******************************/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    // 先统计数组中奇数的个数
        vector<int>::iterator iter2 = nums.end();
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator iter1 = nums.begin();
        vector<int>SubScript;           // 记录奇数的下标
        // 因为需要注意[1,1,2,3,0,2]这种情况
        // 若k为3：如果不记录下标，很容易得到答案为1
        // 实际上答案为3
        // [1,1,2,3] [1,1,2,3,0] [1,1,2,3,0,2]都满足条件
        for(; iter1!=iter2; iter1++){
            if((*iter1)%2 == 1){
                int subScript = distance(begin, iter1);
                SubScript.push_back(subScript);

            }
        }
        int numOfOdds = SubScript.size(); // 奇数的个数
        if(numOfOdds == 0){
            return 0;
        }
        // 边界处理
        SubScript.push_back(nums.size());
        SubScript.insert(SubScript.begin(), -1);         // 扩充SubScript数组，方便后面的计算
        iter1 = SubScript.begin() + 1;
        iter2 = SubScript.end() - 1;
        if(iter2 - iter1 < k){
            return 0;
        }
        int res = 0;
        for(;iter2 - iter1 >=k; iter1++){
            int front = (*iter1) - *(iter1 - 1);
            int back = *(iter1+k) - *(iter1 + k-1);
            res = res + front * back;
        }
        return res;

    }
};
/**********************************
 * 解体思路：
 * 先遍历原数组，求出所有奇数的下标，存储在数组SubScript中；
 * 然后在SubScript中选择连续的k个元素，看一共有几种情况（滑动窗口）；
 * 注意一个窗口两边都可能会扩充（上面注释中说明的情况）；
 * 另外注意边界处理；
 * 这里的边界处理很妙。
*********************************/
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    cout << s.numberOfSubarrays(nums, 2);
    return 0;
}
