//better approach

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans ;
//         map<int,int> mp;
//         int n = nums.size();
//         int mini = (int)n/3 + 1;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]]==mini){
//                 ans.push_back(nums[i]);
//             }
//             if(ans.size()==2) break;
//         }
//         sort(ans.begin(),ans.end());
//         return ans ;
//     }
// };



//optimal approach using moore's voting algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0,el1=INT_MIN, cnt2=0,el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1 ==0 && el2!=nums[i]){
                cnt1 =1;
                el1 = nums[i];
            }
            else if(cnt2 ==0 && el1!=nums[i]){
                cnt2 =1;
                el2 = nums[i];
            }
            else if(nums[i]==el1){
                cnt1++;
            }
            else if(nums[i]==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
         cnt1=0,cnt2=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(el1 == nums[i]){
                cnt1++;
            }
            if(el2 == nums[i]){
                cnt2++;
            }
        }
        int mini = (int)(n/3) +1;
        if(cnt1>= mini){
            ans.push_back(el1);
        }
        if(cnt2>= mini){
            ans.push_back(el2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};