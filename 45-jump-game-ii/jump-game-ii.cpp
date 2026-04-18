
class Solution {
  public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;
        
        int jumps = 0;
        int maxReach = 0;
        int steps = 0;
        
        for(int i = 0; i < n - 1; i++){
            maxReach = max(maxReach, i + arr[i]);
            
            if(i == steps){
                jumps++;
                steps = maxReach;
                
                if(steps <= i) return -1; // stuck
            }
        }
        
        return jumps;
    }
};