/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/reverse-an-array/0/?track=SP-Arrays%20and%20Searching
	Asked in : Moonfroog Labs, Infosys
	
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
	    lint n;
	    cin>>n;
	    lint a[n];
	    for(lint i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(lint i=n-1;i>=0;i--){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
