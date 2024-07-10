class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                c-=(c>0);
            }
            if(logs[i]!="./"&&logs[i]!="../"){
                c++;
            }

        }
        return c;
    }
};