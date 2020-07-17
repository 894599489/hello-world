/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <unordered_set>
#include <queue>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

class Solution {
public:
    bool findNum(TreeNode* root, int k)
    {
        if (root->val == k) {
            return true;
        }
        if (root->val > k) {
            if (root->left != nullptr) {
                return findNum(root->left, k);
            }
        } else {
            if (root->right != nullptr) {
                return findNum(root->right, k);
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) 
    {
        if (root == nullptr) {
            return false;
        }
        std::unordered_set<int> cache;
        std::queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            int v = k - node->val;
            if (cache.find(v) != cache.end()) {
                return true;
            }
            cache.insert(node->val);
            if (node->left != nullptr) {
                if (findNum(node->left, v)) {
                    return true;
                }
                que.push(node->left);
            }
            if (node->right != nullptr) {
                if (findNum(node->right, v)) {
                    return true;
                }
                que.push(node->right);
            }
        }
        return false;
    }
};


int main()
{
    
    return 0;
}