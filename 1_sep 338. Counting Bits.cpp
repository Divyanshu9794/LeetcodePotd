class Solution {
public:
    int bitset(int n){
        int set = 0;
        int unset = 0;

        for(int i = 31;i >= 0;i--){
            if((n & (1 << i)) != 0)
                set++;
            else 
                unset++;
        }
        return set;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);

        for(int i = 1;i <= n;i++){
            v.push_back(bitset(i));
        }
        return v;
    }
};
