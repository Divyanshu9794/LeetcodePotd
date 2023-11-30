class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rulekey, string rulevalue) {
        int n = items.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(rulekey=="type"){
                if(items[i][0]==rulevalue){
                    c++;
                }
            }
            else if(rulekey=="color"){
                if(items[i][1]==rulevalue){
                    c++;
                }
            }
            else{
                if(items[i][2]==rulevalue){
                    c++;
                }
            }
        }
        return c;
        
    }
};