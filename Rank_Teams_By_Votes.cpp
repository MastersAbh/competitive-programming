/*

Leetcode Problem Link : 
https://leetcode.com/problems/rank-teams-by-votes/

*/

class Solution {
public:
    map<char, map<int, int>> mp;
    map<char, bool> visited;
    char getWinner(int teams) {
        set<char> st;
        auto it = mp.begin();
        while (it != mp.end()) {
            if (visited.find(it->first) == visited.end()){
                st.insert(it->first);
            }
            ++it;
        }
        
        for (int i = 0; i < teams; i++){
             priority_queue<pair<int, char>> pq;
             auto it = mp.begin();
             while (it != mp.end()) {
                 if (st.find(it->first) != st.end()) {
                    pq.push({it->second[i], it->first});
                 }
                ++it;
             }
            st.clear();
            int mx = pq.top().first;
            while(!pq.empty()) {
                int x = pq.top().first;
                char c = pq.top().second;
                pq.pop();
                if(x == mx) {
                    st.insert(c);
                } else {
                    break;
                }

            }
            if(st.size() == 1) {
                break;
            }
        }
        
        visited[*st.begin()] = true;
        return *st.begin();
    }
    
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        string ans = "";
        int m = votes[0].length();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < votes[i].length(); j++) {
                mp[votes[i][j]][j]++;
            }
        }
        
        for(int i = 0; i < m; i++) {
            ans+=getWinner(m);
        }
        
        return ans;
  
    }
};
