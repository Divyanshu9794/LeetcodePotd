class Solution {
public:
    int numberOfWays(string corridor) {
        int x = 1; 
        int y = 0; 
        int z = 0; 
        for (char& ch: corridor)
            if (ch == 'S')
                x = (x + z) % int(1e9 + 7), z = y, y = x, x = 0;
            else
                x = (x + z) % int(1e9 + 7);
        return z;
    }
};