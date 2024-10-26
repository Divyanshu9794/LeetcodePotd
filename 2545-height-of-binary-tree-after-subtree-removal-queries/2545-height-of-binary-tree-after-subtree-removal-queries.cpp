class Solution {
    unordered_map<int, int> nodeLevel;
    unordered_map<int, pair<int,int>> heights;
    unordered_map<int,int> height;
public:
    int getHeight(TreeNode* root, int level) {
        if (root == nullptr) return 0;
        int lh = getHeight(root->left, level + 1);
        int rh = getHeight(root->right, level + 1);
        int h = 1 + max(lh, rh);
        
        nodeLevel[root->val] = level;
        height[root->val] = h;
        
        if (heights.count(level)) {
            if (heights[level].first <= h) {
                pair<int,int> p = {h, heights[level].first};
                heights[level] = p;
            } else if (heights[level].second < h) {
                heights[level].second = h;
            }
        } else {
            heights[level] = {h, 0};
        }
        return h;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getHeight(root, 0);
        vector<int> result;
        for (auto node: queries) {
            int level = nodeLevel[node];
            if (height[node] == heights[level].first) {
                result.push_back(heights[level].second + level - 1);
            } else {
                result.push_back(heights[level].first + level - 1);
            }
        }
        return result;
    }
};