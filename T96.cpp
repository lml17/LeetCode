/*************************
 * LeetCode 第96题
 * 给定一个整数n，求以1,2....n节点构成的二叉搜索树有多少种？
 * 2020-07-21
 *************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0){
            return 0;
        }

        if(a.size() >= n){
            return a.begin()[n-1];
        }
        if(a.size() == 0){
            a.push_back(1);    // 一个节点的搜索二叉树有一种
        }
        for(int i = a.size(); i<n; i++){    // i 为数组a的下标
            int numNodes = i + 1;
            int sum = 2 * a[i-1];   // 1为根节点或者n为根节点
            for(int j =2;j<numNodes;j++){
                sum = sum + a[j-2]*a[numNodes-j-1]; // j为根节点，左边有j-1个点，右边有numNodes-j个点
            }
            a.push_back(sum);
        }
        return a[n-1];

    }
private:
    vector<int> a;
};
/*******************************
 * 思路：注意二叉搜索树左右子树的大小特性，
 * 遍历1到n的数字i，以i为根节点，将1到i-1
 * 作为左子树，i+1到n作为右子树，便可以递归
 * 解决该问题。
 * 第二种方法：直接利用数学上的结论：卡特兰数。
 ******************************/
int main(){
    Solution s;
    cout << s.numTrees(3) << endl;;
    return 0;
}
