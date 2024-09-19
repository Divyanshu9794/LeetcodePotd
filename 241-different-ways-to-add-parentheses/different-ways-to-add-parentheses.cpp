class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;

        int i = 0;
        while (i < expression.size()) {
            if (isdigit(expression[i])) {
                int num = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    num = num * 10 + (expression[i] - '0');
                    i++;
                }
                nums.push_back(num);
            } else {
                ops.push_back(expression[i]);
                i++;
            }
        }
        
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        for (int j = 0; j < n; j++) {
            dp[j][j] = {nums[j]};
        }

        for (int length = 2; length <= n; length++) {
            for (int l = 0; l <= n - length; l++) {
                int r = l + length - 1;
                for (int k = l; k < r; k++) {
                    const auto& leftResults = dp[l][k];
                    const auto& rightResults = dp[k + 1][r];
                    char op = ops[k];
                    
                    for (int left : leftResults) {
                        for (int right : rightResults) {
                            if (op == '+') {
                                dp[l][r].push_back(left + right);
                            } else if (op == '-') {
                                dp[l][r].push_back(left - right);
                            } else {
                                dp[l][r].push_back(left * right);
                            }
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};