/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0/?track=SP-Recursion
	Asked in : Samsung, MAQ Software, Amazon, Cisco, Accolite
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

vector<string> v;

void chk(string s,string r){      // r has the permutation while s stores the characters left to be added to the permutation.
    if(s==""){
        v.push_back(r);
        return;
    }
    for(lint i=0;i<s.length();i++){
        chk(s.substr(0,i)+s.substr(i+1,s.length()-1),r+s[i]);   
    }
}


int main() {
    lint t;
    cin>>t;
    while(t--){
        v.clear();
        string s;
        cin>>s;
        string h="";
        chk(s,h);
        sort(v.begin(),v.end());        // lexicographical order
        for(lint i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
