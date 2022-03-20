#include "../leetcode.h"

///////////////////////////////////////////////////
// 94. 二叉树的中序遍历
// ------------------------------------------------
// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
///////////////////////////////////////////////////

void inorder(TreeNode* root, vector<int>& ans)
{
    // 到底啦，不能再走了
    if (!root) return;

    // 前序遍历：root ▶ left ▶ right
    // 中序遍历：left ▶ root ▶ right
    // 后序遍历：left ▶ right ▶ root
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main(int argc, char** argv)
{
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;
    display(inorderTraversal(&a));
    return 0;
}