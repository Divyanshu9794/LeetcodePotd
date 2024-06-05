class Solution {
public:
vector<string> commonChars(vector<string>& words)
{
    vector<string> ans;
    vector<int> minFreq(26, INT_MAX);
    for (auto word : words)
    {
        vector<int> freq(26, 0);
        for (auto j : word)
        {
            freq[j - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            minFreq[i] = min(minFreq[i], freq[i]);
        }
    }

    for(int ch =0; ch<26; ch++)
    {
       while(minFreq[ch] > 0){
        ans.push_back(string(1,ch+'a'));
        minFreq[ch]--;
       }
    }
    
    return ans;
}
};