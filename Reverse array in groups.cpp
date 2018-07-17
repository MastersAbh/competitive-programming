/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0/?track=SP-Arrays%20and%20Searching
	
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
	    lint k;
	    cin>>k;
	    lint j = 0;				// j points to the index of first element of the current subarray
	    while(j<n){				
	        for(lint i=min(j+k-1,n-1);i>=j;i--){	// iterates and prints from last element of the subarray to the first.
	            cout<<a[i]<<" ";
	        }
	        j+=k;				// shifting to the next subarray
	    }
	    cout<<endl;
	}
	return 0;
}
