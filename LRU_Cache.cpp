#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
   string s="123145";
   deque<char> dq;
   map<char, deque<char>::iterator> mp;
   for(ll i=0;i<s.length();i++)
   {
       if(mp.find(s[i])==mp.end())
       {
           if(dq.size()==4)
           {
            char last= dq.back();
            dq.pop_back();
            mp.erase(last);
           }
       }
       else
           dq.erase(mp[s[i]]);
       dq.push_front(s[i]);
       mp[s[i]]=dq.begin();
   }
   for(auto it=dq.begin();it!=dq.end();it++)
   {
       cout<<*it<<endl;
   }
}
