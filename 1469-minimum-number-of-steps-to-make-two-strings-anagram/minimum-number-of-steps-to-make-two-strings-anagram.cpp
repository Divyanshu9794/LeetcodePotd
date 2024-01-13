class Solution {
public:
    int minSteps(string a, string b) {
        int arr[26] ={0};
        int c=0;
        for(int i=0; i<a.length(); i++)
            arr[a[i]-97] += 1;

        for(int i=0; i<b.length(); i++)
            arr[b[i]-97] -= 1;
            
        for(int i=0; i<26; i++)
            if(arr[i] > 0)
                c+=arr[i];
        return c;
    }
};