class Solution {
public:
    int bulbSwitch(int n) {
      
      int count = 0;
    for (int i = 1; i <= n; i++) {
        int squareRoot = sqrt(i);
        if (squareRoot * squareRoot == i) {
            count++;
        }
    }
    return count;
 
    }
};