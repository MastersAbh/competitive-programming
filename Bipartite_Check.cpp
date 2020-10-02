#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int isBipartitite(vector<ll> adj[],int u, vector<ll> color)
{
    for(ll j = 0; j < adj[u].size(); j++)
    {
        if (color[adj[u][j]] == -1){
            color[adj[u][j]] = 1 - color[u];
            return isBipartitite(adj, adj[u][j], color);
        }
        if (color[u] == color[adj[u][j]]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll x, y;
    vector<ll> adj[n + 1];
    for(ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> color(n+1, -1);
    int ans;
    if (color[1] == -1) {
        color[1] = 1;
        ans = isBipartitite(adj , 1, color);
    }
    if (ans == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

/*
Input:
4 3
1 2
2 3
3 4
Output:
Yes
*/
