/*

Leetcode Problem Link : 

https://leetcode.com/problems/merge-similar-items/

*/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        int n = items1.size();
        int m = items2.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[items1[i][0]] += items1[i][1];
        }
         for (int i = 0; i < m; i++){
            mp[items2[i][0]] += items2[i][1];
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> v;
            v.push_back(it->first);
            v.push_back(it->second);
            ans.push_back(v);
        }
        return ans;
        
    }
};
