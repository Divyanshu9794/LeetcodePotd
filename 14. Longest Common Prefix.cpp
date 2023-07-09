class Solution {
public:

    string longestCommonPrefix(vector<string>& arr) {
        int n= arr.size();
        string ans;
        for(int i = 0; i < arr[0].length(); i++){
            char curr = arr[0][i];
            bool match = true;
            for(int j = 1; j < n; j++){
                if(!(arr[j].length() > i && arr[j][i] == curr)){
                    match = false;
                    break;
                }
            }
            if(match){
                ans.push_back(curr);
            }
            else{
                break;
            }
        }

        return ans;
    }
};
