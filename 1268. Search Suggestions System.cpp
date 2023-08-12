class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>res;
        string temp="";
        int low=0,high=0;
        for(int i=0;i<searchWord.length();i++){
            temp+=searchWord[i];
            low=lower_bound(products.begin()+high,products.end(),temp)-products.begin();
            res.push_back({});
            for(int j=low;(j<(low+3) && j<products.size()) && (!products[j].compare(0,temp.size(),temp));j++){
                res.back().push_back(products[j]);
            }
            high=low;
                
        }
        return res;
        
    }
};
