/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0/?track=SP-Arrays%20and%20Searching
	Asked in : Amazon, MAQ Software
	
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
	    lint d;
	    cin>>d;
	    for(lint i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(lint i=d;i<n;i++){	// The idea is to first print all elements starting at index d
	        cout<<a[i]<<" ";
	    }
	    for(lint i=0;i<d;i++){	// Then print all elements from 1st upto index d. This way thr rotated array is printed without actually rotating it.
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	
	
	return 0;
}
