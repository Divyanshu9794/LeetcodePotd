class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        if(n<=2){
            return true;
        }
        sort(arr.begin(),arr.end());
        int dif=arr[1]-arr[0];
        for(int i=2;i<n;i++){
            if(dif!=(arr[i]-arr[i-1])){
                return false;
            }
        }
        return true;
    }
};
