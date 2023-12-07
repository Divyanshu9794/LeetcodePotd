class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.length();
        int j=-1;
        for(int i=n-1;i>=0;i--)
        {
            int num=(int)(s[i]-'0');
            if(num%2!=0)
            {
                j=i;
                break;
            }
        }
        if(j==-1)
            return "";
        string t="";
        for(int i=0;i<=j;i++)
            t+=s[i];
        return t;
    }
};