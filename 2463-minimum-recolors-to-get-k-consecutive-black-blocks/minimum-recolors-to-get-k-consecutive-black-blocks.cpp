class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int lef=0,totalwhite=0,numberofrecolor = INT_MAX;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='W'){
                totalwhite++;
            }
            if(i-lef+1 == k){
                numberofrecolor = min(numberofrecolor,totalwhite);
                if(blocks[lef]=='W'){
                    totalwhite--;
                }
                lef++;
            }
        }
        return numberofrecolor;
    }
};