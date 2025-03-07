class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = 1e6;
        for (int i = left; i <= right; i++) {
            if (isprime(i)) {
                if (prevPrime != -1) {
                    int difference = i - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = i;
                    }
                    if (difference == 2 or difference == 1)
                        return {prevPrime, i};
                }
                prevPrime = i;
            }
        }

        return (closestA == -1) ? vector<int>{-1, -1}
                                : vector<int>{closestA, closestB};
        
    }
    bool isprime(int num){
        if(num<2){
            return false;

        }
        if(num ==2 || num==3){
            return true;
        }
        if(num %2==0){
            return false;
        }
        for(int i=3;i*i<=num;i+=2){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
};