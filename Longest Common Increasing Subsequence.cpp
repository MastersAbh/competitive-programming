/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/longest-common-increasing-subsequence/0/?track=SP-Arrays%20and%20Searching
	
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
    while(t--){				// We use dynamic programming approach in a combination of LIS and LCS, to generate LICS
        lint n;
        cin>>n;
        lint a[n];
        for(lint i=0;i<n;i++){
            cin>>a[i];
        }
        lint m;
        cin>>m;
        lint b[m];
        for(lint i=0;i<m;i++){
            cin>>b[i];
        }
        lint chk[m]={0};
        lint mx=0;
        for(lint i=0;i<n;i++){			// Iterating every element of1st array through the elements of second array. O(m*n)
            lint c=0;
            for(lint j=0;j<m;j++){
                if(a[i]==b[j]){
                    if(c+1>chk[j]){		// When a common element is found in both arrays
                        chk[j]=c+1;
                        mx=max(mx,chk[j]);		// Stores max length of the LCIS
                    }
                }
                else if(b[j]<a[i]){		// finding the highest element smaller than the current element.
                    if(c<chk[j]){
                        c=chk[j];
                    }
                }
            }
        }
        cout<<mx<<endl;
        
    }
	return 0;
}
