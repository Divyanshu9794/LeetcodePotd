class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n= word.size();
        int ans =0;
        for(int ind=0;ind<n;ind++){
            int a=0,e=0,i=0,o=0,u=0,c=0;
            for(int j=ind;j<n;j++){
                if(word[j]=='a'){
                    a++;
                }
                else if(word[j]=='e'){
                    e++;
                }
                else if(word[j]=='i'){
                    i++;
                }
                else if(word[j]=='o'){
                    o++;
                }
                else if(word[j]=='u'){
                    u++;
                }
                else{
                    c++;
                }
                if(a && e && i && o && u && c==k){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};