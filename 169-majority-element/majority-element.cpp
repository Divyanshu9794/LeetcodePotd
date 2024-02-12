class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unsigned i, check, counter = 0;
    int result = 0;
    
    for(check = 1; check; check <<= 1, counter &= 0){
        
        for(i = 0; i < nums.size(); ++i)
            if( check & nums[i] ) ++counter; 
        
        
        if( counter > ( nums.size() >> 1 ) ) result |= check;
    }
    
    return result;  
    }
};