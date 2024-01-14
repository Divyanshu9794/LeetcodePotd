class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        unordered_map<char,int> temp1;
        unordered_map<int,string> w1;
        for(int i=0;i<word1.length();i++)
            temp1[word1[i]]++;
        for(auto it : temp1){
            w1[it.second].push_back(it.first);
        }
        unordered_map<char,int> temp2;
        unordered_map<int,string> w2;
        for(int i=0;i<word2.length();i++)
            temp2[word2[i]]++;
        for(auto it : temp2){
            w2[it.second].push_back(it.first);
        }
        if(w1.size() != w2.size())
            return false;
        string m,n;
        for(auto it : temp1){
            // cout << it.first;
            m += it.first;
        }
        for(auto it : temp2){
            n += it.first;
        }
        sort(m.begin(),m.end());
        sort(n.begin(),n.end());
        // cout << m << n << endl;
        if(m!=n)
        return false;
        for(auto it : w1){
            if(w2[it.first].size()!=it.second.size())
                return false;
        }
        return true;
    }
};