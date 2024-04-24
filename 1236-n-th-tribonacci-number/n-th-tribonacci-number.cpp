class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        int p3=0, p=1,p2=1;
        for(int i=3;i<=n;i++){
            int c=p+p2+p3;
            p3=p2;
            p2=p;
            p=c;
        }
        return p;
        
    }
};