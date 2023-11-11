class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxword=0;
        int n= sentences.size();
        for(int i=0;i<n;i++){
            int m = sentences[i].size();
            int word=1;
            for(int j=0;j<m;j++){
                if(sentences[i][j]==' '){
                    word++;
                }
                maxword= max(maxword,word);
            }
        }
        return maxword;
        
    }
};