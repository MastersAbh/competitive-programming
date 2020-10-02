#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0;i<n;i++){
		if (nums[i] <= 0){
			nums[i] = n+1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (abs(nums[i]) <= n) {
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return i+1;
        }
    }
    return n+1;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << firstMissingPositive(nums) << endl;
}

/*
Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1
*/
