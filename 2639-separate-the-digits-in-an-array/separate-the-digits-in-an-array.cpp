class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto a: nums){
            vector<int> temp;
            while(a > 0){
                temp.push_back(a%10);
                a = a/10;
            }
            for(int i = temp.size()-1; i >= 0; --i){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};