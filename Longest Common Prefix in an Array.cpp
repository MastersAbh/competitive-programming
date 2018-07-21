/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0/?track=SP-Arrays%20and%20Searching
	Asked in: VMWare
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)


*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

string chk(string a,string b){		// Function that returns the longest common prefix between two strings
    lint i=a.length();
    string s=b.substr(0,i);
    while(i>1 && a!=s){
        i--;
        s=s.substr(0,i);
        a=a.substr(0,i);
    }
    if(a!=s){
        return "";
    }
    return s;
}

int main() {
	lint t;
	cin>>t;
	while(t--){
	    lint n;
	    cin>>n;
	    string s[n];
	    cin>>s[0];
	    string pre=s[0];
	    lint flag=1;
	    for(lint i=1;i<n;i++){
	        cin>>s[i];
	        pre=chk(pre,s[i]);		// Idea is to find LCP between current LCP and the new string. This will give us cocmbined LCP of the array.
	        if(pre==""){
	            flag=0;				// No common prefix.
	        }
	    }
	    if(flag==0){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<pre<<endl;
	    }
	}
	return 0;
}

