int getBitsCount(int num){
    int cnt = 0;
    while(num != 0){
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt;
}

bool compare(int a, int b){
    int abits = getBitsCount(a);
    int bbits = getBitsCount(b);
    if(abits == bbits) return a < b;
    return abits < bbits;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};