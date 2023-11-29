class Solution {
public:
    int hammingWeight(uint32_t n) {
     uint32_t b = n;
int count = 0;
while(b>0){
    if (b%2==1){
        count++;
    }
    b/=2;
}
return count;
    }
};