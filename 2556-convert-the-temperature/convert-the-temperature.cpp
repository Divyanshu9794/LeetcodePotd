class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double k = celsius+273.15;
        ans.push_back(k);
        double f = celsius * 1.80 +32;
        ans.push_back(f);
        return ans;
        
    }
};