class Solution {
public:
    long long coloredCells(int n) {
        return (long long)(pow(n,2) + pow((n-1),2));
        
    }
};