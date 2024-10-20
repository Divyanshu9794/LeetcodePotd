class Solution {
public:
    pair<int, bool> exp(string s,int i,int n)
    {
        if(s[i]=='f') return {i,false};
        else if(s[i]=='t') return {i,true};
        char x=s[i]; bool y;int k=0;i=i+2;
        while(i<n && s[i]!=')')
        {
           bool z;
           if(s[i]=='f' || s[i]=='t')
           {
               if(s[i]=='f') z=false;
                  else z=true;
           }
           else if(s[i]=='|' ||s[i]=='&' || s[i]=='!') 
           {
             pair<int, bool>p=exp(s,i,n);
             i=p.first;
             z=p.second;
           }
           if(k==0)
           {
               if(x=='!') y=!z;
               else y=z;
               k++;
           }
           else 
           {
                if(x=='!') y=!z;
                else if(x=='&') y=y&z;
                else y=y|z;
           }
           i++;
        }
        return {i,y};
    }
    bool parseBoolExpr(string s) 
    {
       int n=s.size();
      pair<int, bool>p= exp(s,0,n);
      return p.second;
    }
};