/*

Leetcode Problem link : 

https://leetcode.com/problems/container-with-most-water/

*/

class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r) {
            ans = max(ans, min(a[l], a[r]) * (r-l)); 
            if( a[l] >= a[r]) {
                r--;
            } else {
                l++;
            }
            
        }
        return ans;
        
    }
};
