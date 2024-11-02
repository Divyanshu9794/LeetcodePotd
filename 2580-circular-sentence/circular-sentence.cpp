class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i = 0;
        int j = sentence.length()-1;
        if(sentence[i]!=sentence[j]) return false;
        for(i = 0; i<j; i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!= sentence[i+1]) return false;
            }
        }
        return true;
    }
};