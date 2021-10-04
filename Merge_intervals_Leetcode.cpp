class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector < vector <int> > ans;
        for(int i = 0; i < arr.size(); i++) {
            sort(arr.begin(), arr.end());
            int j = i+1, mini = arr[i][0], maxi = arr[i][1];
            while(j < arr.size()) {
                if(arr[j][0] > maxi) {
                    break;
                }
                maxi = max(maxi, arr[j][1]);
                mini = min(mini, arr[j][0]);
                j++;
            }
            i = j-1;
            ans.push_back({mini, maxi});
        }
        return ans;
    }
};
