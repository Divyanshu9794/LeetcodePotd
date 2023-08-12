class Solution {
public:
    int numTilings(int n) {
        int first  = 0 ,second = 1 , third = 1 , next , mod = 1e9+7 ;
        while(--n)
        {
            next = ((third * 2) %mod + first)%mod ;
            first = second ;
            second = third ;
            third = next ;
        }
        return third ;
    }
};
