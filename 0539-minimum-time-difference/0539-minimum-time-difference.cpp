class Solution {
public:
    int mod=1440;// 24*60
    int findMinDifference(vector<string>& s) {
        sort(s.begin(),s.end());
        int res=INT_MAX;
        for(int i=1;i<s.size();i++)
        {
            res=min(res,fun(s[i-1],s[i]));
        }
        // first and last diff could be min as last + some min may go to first
        res=min(res,fun(s[0],s[s.size()-1]));
        return res;
    }
    int fun(string& a,string& b)
    {
        int p=convert(a);
        int q=convert(b);
        int x=min(p,q);
        int y=max(p,q);
        return min(abs(y-x),abs(mod-y+x));
    }
    int convert(string& a)// time to minutes
    {
        int t=0;
        int p=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==':')
            {
                p=t*60;
                t=0;
            }
            else
                t=t*10+a[i]-'0';
        }
        return p+t;
    }
};