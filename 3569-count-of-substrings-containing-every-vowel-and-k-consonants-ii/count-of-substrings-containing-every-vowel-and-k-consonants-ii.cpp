class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return count(word,k)- count(word,k+1);
    }
    bool isvowel(char c){
        return (c=='a' || c=='e'|| c=='i' || c=='o'|| c=='u');
    }
    long long count(string word,int k){
        long long ans =0;
        int l=0,r=0,conscount =0;
        unordered_map<char,int> vowl;
        while(r<word.size()){
            if(isvowel(word[r])){
                vowl[word[r]]++;
            }
            else{
                conscount++;
            }
            while(vowl.size()==5 && conscount>=k){
                ans += word.length()-r;
                if(isvowel(word[l])){
                    if(--vowl[word[l]]==0){
                        vowl.erase(word[l]);
                    }
                }
                else{
                    conscount--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
