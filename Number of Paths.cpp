/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/number-of-paths/0/?track=SP-Recursion
	Asked in : Microsoft, Amazon
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

lint chk(lint i,lint j,lint m,lint n){
    if(i==m-1 && j==n-1){                   // Bottom right cell reached.
        return 1;
    }
    if(i>=m || j>=n){                       // Boundary crossing condition.
        return 0;
    }
    return chk(i+1,j,m,n)+chk(i,j+1,m,n);   // Sum of no. of paths going down + going right.
}

int main() {
    lint t;
    cin>>t;
    while(t--){
        lint n,m;
        cin>>m>>n;
        cout<<chk(0,0,m,n)<<endl;
    }
	return 0;
}
