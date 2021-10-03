/**
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
**/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k==1){
            return nums[0];
        }
        return quickSelect(nums, 0, n-1, n-k);     
    }
    
    int quickSelect(vector<int> nums, int l, int r, int k){
        if(l == r){
            return nums[l];
        }
        if(l < r){
            int pIndex = partition(nums, l, r);
            if(pIndex == k){
                return nums[k];
            } else if(pIndex < k){
                return quickSelect(nums, pIndex+1, r, k);
            } else if(pIndex > k){
                return quickSelect(nums, l, pIndex-1, k);
            }
        }
        return nums[l];
    }
    
    int partition(vector<int>& nums, int l, int r){
        int i = l, j = l;
        int pIndex = r;   
        for(j = l; j < r; j++){
            if(nums[j] <= nums[pIndex]){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[pIndex]);
        return i;
    }
};