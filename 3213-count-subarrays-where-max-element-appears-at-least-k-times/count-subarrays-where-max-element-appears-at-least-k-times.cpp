class Solution { 
public: 
    long long countSubarrays(vector<int>& arr, int k) { 
        long long  n = arr.size(); 
        long long  maxi = *max_element(arr.begin(), arr.end()); 
        long long i = 0, j = 0, c = 0, res = 0; 
        while (j < n) { 
            if (arr[j] == maxi) { 
                c++; 
            } 
            if (c >= k) { 
                while (c >= k) { 
                    res += n - j; 
                    if (arr[i] == maxi) { 
                        c--; 
                    } 
                    i++; 
                } 
            } 
            j++; 
        } 
        return res; 
    } 
}; 