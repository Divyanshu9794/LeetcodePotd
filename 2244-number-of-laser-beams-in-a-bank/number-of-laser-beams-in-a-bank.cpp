class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0,p=0;
        for(auto &a:bank){
            int c=count(a.begin(),a.end(),'1');
            if(c==0){
                continue;
            }
            res += (p*c);
            p=c;
        }
        return res;
    }
};