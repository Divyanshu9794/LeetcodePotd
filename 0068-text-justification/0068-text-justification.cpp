class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(),i=0;
        vector<string>ans;
        while(i<n){
            int w=0,st=i,len=0;
            while(i<n and len+w+words[i].size()<=maxWidth){
                len+=words[i].size();
                w++;
                i++;
            }
            string tmp=words[st++];
            int extra=maxWidth-len;
            if(w==1){
                tmp+=string(extra,' ');
                ans.push_back(tmp);
                continue;
            }
            if(i==n){
                while(st<i){
                    tmp+=' ';
                    extra--;
                    tmp+=words[st++];
                }
                tmp+=string(extra,' ');
                ans.push_back(tmp);
                continue;
            }
            w--;
            while(w and st<i){
               
                tmp+=string(extra/w+(extra%w>0),' ');
               
                tmp+=words[st++];
                extra-=extra/w+(extra%w>0);
                
                w--;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};