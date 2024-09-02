class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalchalk=0;
        for(int chalkused : chalk){
            totalchalk+=chalkused;
        }
        int remaining  = k % totalchalk;

        for(int i=0;i<chalk.size();i++){
            if(remaining <chalk[i]){
                return i;
            }
            remaining -= chalk[i];
        }
        return 0;

    }
};