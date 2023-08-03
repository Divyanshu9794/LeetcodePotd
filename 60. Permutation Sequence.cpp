class Solution
{
public:
    string getPermutation(int n, int k)
    {
        // code here
        int factorial = 1;
        vector<int> number;
        for(int i=1;i<n;i++){
            factorial = factorial*i;
            number.push_back(i);
        }
        number.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans = ans + to_string(number[k/factorial]);
            number.erase(number.begin() + k/factorial);
            if(number.size()==0){
                break;
            }
            k=k%factorial;
            factorial = factorial/number.size();
        }
        return ans;
    }
};
