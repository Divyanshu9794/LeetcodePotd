class Solution {
public:
    vector<int> getRow(int rowindex) {
        vector<int> ansrow;
        long long ans =1;
        ansrow.push_back(ans);
        for(int i=1;i<=rowindex;i++){
            ans = ans * (rowindex-i+1);
            ans = ans / (i);
            ansrow.push_back(ans);
        }
        return ansrow;
    }
};