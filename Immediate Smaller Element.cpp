/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0/?track=SP-Arrays%20and%20Searching
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
        for(lint i=1;i<n;i++){
            cin>>a[i];
            if(a[i]<a[i-1]){			// If current element is smaller than the previous element, print it
                cout<<a[i]<<" ";
            }
            else{						// else print -1
                cout<<-1<<" ";
            }
        }
        cout<<-1<<endl;					// The last element has no next element, so print -1.
    }
	
}