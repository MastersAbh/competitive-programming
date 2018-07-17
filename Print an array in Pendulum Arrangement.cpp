/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/print-an-array-in-pendulum-arrangement/0/?track=SP-Arrays%20and%20Searching
	
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
        sort(a,a+n);
        lint b[n];				// To store the resulting array
        lint x = (n-1)/2;		// points to the left side of pendulum
        lint y = x+1;			// The right counterpart
        for(lint i=0;i<n;i+=2){
            if(x>=0){
                b[x]=a[i];
                x--;
            }
            if(y<n){
                b[y]=a[i+1];
                y++;
            }
        }
        for(lint i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
