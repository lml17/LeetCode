/************************
 * LeetCode 第154题
 * 寻找旋转排序数组中的最小值
 * 一个按照升序排列的数组在预先未知的某个点上进行了旋转
 * 如：数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]
 * 找出其中最小的元素
 * 2020-07-22
 ************************/
# include <iostream>
# include <vector>
# include <iterator>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int>::iterator iter1 = nums.begin();
        vector<int>::iterator iter2 = nums.end() - 1;

        for(;iter1<iter2;iter1++){
            if((*iter1) > (*(iter1 + 1)))
                break;
        }
        if(iter1 == iter2){
            iter1 = nums.begin();
            return *(iter1);
        }
        else {
            return *(iter1 + 1);
        }
    }
};

/*******************************
 * 思路一：找出序列中第一个变小的元素即可
 * 思路二：二分查找，注意可能有重复的元素
 *******************************/

int main(){
    Solution s;
    vector<int> n;
    n.push_back(3);
    n.push_back(1);
    cout << s.findMin(n) << endl;
    return 0;
}
