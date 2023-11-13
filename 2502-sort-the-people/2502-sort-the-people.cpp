class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int , string>> p;
        for(int i=0;i<n;i++){
            p.push_back({heights[i],names[i]});
        }
        sort(p.rbegin(),p.rend());
        vector<string > res;
        for(auto i:p){
            res.push_back(i.second);
        }
        return res;
    }
};