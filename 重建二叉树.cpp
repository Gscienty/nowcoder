#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* recon_self(vector<int>::iterator pre_begin,
                     vector<int>::iterator pre_end,
                     vector<int>::iterator vin_begin,
                     vector<int>::iterator vin_end) {
    if (pre_begin == pre_end) {
        return NULL;
    }

    TreeNode *root = new TreeNode(*pre_begin);

    vector<int>::iterator mid = find(vin_begin, vin_end, *pre_begin);

    int left = mid - vin_begin;

    root->left = recon_self(pre_begin + 1, pre_begin + left + 1, vin_begin, mid);
    root->right = recon_self(pre_begin + left + 1, pre_end, mid + 1, vin_end);

    return root;
}

TreeNode* recon(vector<int> pre, vector<int> vin) {
    return recon_self(pre.begin(), pre.end(), vin.begin(), vin.end());
}
