class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& i : operations) {
            if (i[1] == '+') x++;
            else x--;
        }
        return x;
    }
};
