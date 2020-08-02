/*********************************
 * LeetCode 第114题：二叉树展开为链表
 * 具体描述参见官网 https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 * Date：2020-08-02
 *********************************/
#include <iostream>

using namespace std;


// 二叉树的节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* root_copy = root;
        TreeNode* r = root;
        while(r != nullptr){
            if(r->right == nullptr){
                r = r->left;
                continue;
            }
            if(r->left == nullptr){
                r->left = r->right;
                r->right = nullptr;
                r = r->left;
                continue;
            }
            TreeNode* temp = r->left;
            TreeNode* mostRight = findMostRight(temp);
            mostRight->right = r->right;
            r->right = nullptr;
            r = r->left;
            continue;
        }
        Reverse(root_copy);
    }
    // 找到以t为根节点的二叉树的最右边的点（一路向右）
    TreeNode* findMostRight(TreeNode* t){
        if(t == nullptr){
            return t;
        }

        TreeNode* res = t;
        while(res->right !=nullptr){
            res = res->right;
        }
        return res;
    }
    // 将一棵 一直向左的二叉树 反转为 一直向右的二叉树
    void Reverse(TreeNode* root){
        while(root != nullptr){
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
};

/************************************
 * 解体方法：
 * 法一：展开为链表的顺序与前序遍历的结果一致，
 *  所以可以考虑先前序遍历得到输出顺序，
 *  然后再依据这个顺序恢复出题目要求的解的形式。
 *  注意这种方法可能不是“原地”的。
 * 法二（该代码使用的方法）：与官方提供的方法三一致，https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
 *  注意“前驱节点”的概念。
 ************************************/
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
