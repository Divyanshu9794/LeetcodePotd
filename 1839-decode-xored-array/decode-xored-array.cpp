class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int element = first;
        for(int i = 0 ; i < encoded.size() ; i++)
        {
            int t = element^encoded[i];
            element = t;
            ans.push_back(element);
        }
        return ans;
    }
};