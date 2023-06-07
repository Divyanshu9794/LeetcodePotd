class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        while(a>0 || b>0 || c>0){
            int bta=a&1;
            int btb=b&1;
            int btc=c&1;
            if((bta|btb)!=btc){
                if(btc==1){
                    flip++;
                }
                else{
                    flip +=  (bta+btb);
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;

        }
        return flip;
    }
};
