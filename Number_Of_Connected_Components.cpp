#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mkp make_pair
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        ll x,y;
        vector<ll> adj[n];
        for(ll i=0;i<m;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n,false);
        ll c=0;
        for(ll i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                c++;
                stack<ll> s;
                s.push(i);
                visited[i]=true;
                while(!s.empty())
                {
                  ll p=s.top();
                    s.pop();
                    for(ll j=0;j<adj[p].size();j++)
                    {
                        if(!visited[adj[p][j]])
                        {
                            s.push(adj[p][j]);
                            visited[adj[p][j]]=true;
                        }
                            
                    }
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
