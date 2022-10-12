#include <iostream>
using namespace std;


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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // both trees are null, return true
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // one tree is null but the other is not
        else if (p == nullptr || q == nullptr) {
            return false;
        }

        // there is a value for each node
        // but the values are NOT equal
        else if (p->val != q->val) {
            return false;
        }

        // this is our recursive case
        // we continue to find equal values at each node
        else {
            // test left side of both
            // test right side of both
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
int main()
{
    Solution solution;

    TreeNode tree_one_node_three(3);
    TreeNode tree_one_node_two(2);
    TreeNode tree_one_root_node(1, &tree_one_node_two, &tree_one_node_three);


    TreeNode tree_two_node_three(3);
    TreeNode tree_two_node_two(2);
    TreeNode tree_two_root_node(1, &tree_two_node_two, &tree_two_node_three);

    cout << "Example One : " << solution.isSameTree(&tree_one_root_node, &tree_two_root_node) << endl;

	return 0;
}
