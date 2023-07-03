class Solution {
public:

    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        vector<int> after(2*k+1,0);
        vector<int> curr(2*k+1,0);
        for(int ind =n-1;ind>=0;ind--){
            for(int transno=2*k-1;transno>=0;transno--){
                if(transno %2 ==0){
                   curr[transno]=max(-a[ind] + after[transno+1],after[transno]);
                }
                else  curr[transno]= max(a[ind]+after[transno+1],after[transno]);
            }
            after=curr;
        }
        return after[0];
    }
};
