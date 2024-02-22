class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(trust.size()==0)
        {
            if(n==1)
            {
                return 1;
            }
            return -1;
        }
        unordered_map<int,int>trustedbyhowmany;
        unordered_map<int,bool>trustsanyone;
        for(int i=0;i<trust.size();i++)
        {
            trustedbyhowmany[trust[i][1]]++;
            trustsanyone[trust[i][0]]=true;
        }
        for(auto j:trustedbyhowmany)
        {
            if(!trustsanyone[j.first] && j.second==(n-1))
            {
                return j.first;
            }
        }
        return -1;
    }
};