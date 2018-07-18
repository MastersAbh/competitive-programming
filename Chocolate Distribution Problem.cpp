/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0/?track=SP-Arrays%20and%20Searching
	Asked in : Flipkart
	
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
        sort(a,a+n);				// We only need to sort the array. Any combination will be selected on a continuos basis.
        lint m;
        cin>>m;
        lint mn = 100001;
        for(lint i=0;i+m-1<n;i++){
            mn=min(mn,a[i+m-1]-a[i]);	// Answer is minimum possible difference between 1st and last number in a continuous sequence of m numbers of the sorted array.
        }
        cout<<mn<<endl;
    }
	return 0;
}
