
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int n = arr.size();
        int low = 0, hi = n-1;
        while(low<=hi){
            int mid = (low + hi)/2;
            if(arr[mid]==key){
                return true;
            }
            if(arr[low]== arr[mid] && arr[mid]==arr[hi]){
                low++;
                hi--;
                continue;
            }
            if(arr[low]<=arr[mid]){
                if(arr[low]<=key && key<= arr[mid]){
                    hi = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(arr[mid]<= key && key<= arr[hi]){
                    low = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return false;
    }
};