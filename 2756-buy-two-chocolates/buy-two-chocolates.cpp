class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        nth_element(prices.begin(), prices.begin()+1, prices.end());
        int moneyleft =money - prices[0]-prices[1];
        if(moneyleft>=0){
            return moneyleft;
        }
        else{
            return money;
        }
        
    }
};