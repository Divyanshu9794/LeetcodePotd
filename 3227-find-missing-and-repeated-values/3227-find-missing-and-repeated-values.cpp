class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        int siz = n*n;
        int repeating =0,missing =0;
        int sum = (siz*(siz+1))/2;
        unordered_set<int> s;
        for(auto &i: grid){
            for(int a: i){
                s.insert(a);
            }
        }
        int stsum=0;
        for(auto x:s){
            stsum+=x;

        }
        missing = sum-stsum;
        int arraysum =0;
        for(auto &i: grid){
            for(int a: i){
                arraysum+=a;
            }
        }
        repeating = arraysum-stsum;
        // for(int i=1;i<=n*n;i++){
        //     if(!mp.count(i)){
        //         missing= i;
        //     }
        //     else if(mp[i]==2){
        //         repeating = i;
        //     }
        // }

        return {repeating,missing};
        
    }
};