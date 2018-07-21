/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/?track=SP-Arrays%20and%20Searching
	Asked in : Amazon
	
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
	    cin>>a[0];
	    lint m=a[0];				// m will store the max element of the array
	    lint b[2]={0};				// b[0] will maintain the count of pairs where a[i]<a[i-1] and b[1] where a[i]>a[i-1]
	    for(lint i=1;i<n;i++){
	        cin>>a[i];
	        m=max(m,a[i]);
	        if(a[i]<a[i-1]){
	            b[0]++;
	        }
	        else{
	            b[1]++;
	        }
	    }
	    cout<<m<<" ";				// Max element will be common
	    if(b[0]==0){
	        cout<<1;				// when no decreasing pair found, it is ascending
	    }
	    else if(b[1]==0){			// when no increasing pair found, it is descending
	        cout<<2;
	    }
	    else if(b[1]==1){			// only 1 increasing pair, decreasing rotated
	        cout<<3;
	    }
	    else{						// only 1 decreasing pair, ascending rotated
	        cout<<4;
	    }
	    cout<<endl;
	}
	return 0;
}

