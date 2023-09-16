class Solution {
public:

    vector<vector<string>> ans;
    bool palindrome(string a){
        int n = a.size();
        for(int i=0;i<(n/2);i++){
            if(a[i]!=a[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void find(string s,int i,vector<string> v)
    {
        if(i>=s.size()){
            ans.push_back(v);
            return ;
        }

        string a = "";
        for(int k=i;k<s.size();k++){
            a+=s[k];
            if(palindrome(a)){
                v.push_back(a);
                find(s,k+1,v);
                v.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string S) {
        find(S,0,{});
        return ans;
    }
    
};
