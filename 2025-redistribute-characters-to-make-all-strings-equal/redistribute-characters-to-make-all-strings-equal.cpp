class Solution {
public:
     bool makeEqual(vector<string>& words) {
        vector<int> freq(26);
        for(auto &word : words){
            for(char c : word){
                freq[c-'a']++;
            }
        }
        int sz = words.size();
        for(int indx = 0; indx < 26; indx++){
            if(freq[indx] && freq[indx] % sz != 0)return false;
        }
        return true;
    }
};