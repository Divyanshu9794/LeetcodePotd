class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st =0;
        int e = n-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
        
    }
};