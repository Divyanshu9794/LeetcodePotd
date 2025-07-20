class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        int n = candyType.size()/2;
        for(int x: candyType){
            mp[x++];
        }
        if(n<=mp.size()){
            return n;
        }
        return mp.size();


        
    }
};