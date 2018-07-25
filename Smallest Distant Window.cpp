/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
	Asked in : Amazon, Dailyhunt
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int
int main() {
	lint t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    map<char,lint> mp;
	    set<char> d;
	    lint m =INT_MAX,n=s.length(),c=0,j=0;
	    for(lint i=0;i<s.length();i++){
	        d.insert(s[i]);
	    }
	    lint l=d.size();
	    d.clear();
	    d.insert(s[0]);
	    mp[s[0]]++;
	    if(n==1){
	        cout<<1<<endl;
	        continue;
	    }
	    for(lint i=1;i<n;i++){
	        
	        d.insert(s[i]);
	        mp[s[i]]++;         // Count of characters in current substring.
	        while(mp[s[j]]>=2){   // When multiple characters already present in current substring, we shift from left.
               mp[s[j]]--;
	           j++;
	        }
	        if(d.size()==l){
	            
	           // cout<<i<<" "<<j<<endl;
	            m=min(m,i-j+1);     // After all the characters are already added, we find min size.
	        }
	    }
	    
	    cout<<m<<endl;
	}
	return 0;
}
