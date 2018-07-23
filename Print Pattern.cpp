/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/print-pattern/0/?track=SP-Recursion
	Asked in : Microsoft
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

void chk(lint s,lint n,lint c){
    if(s==n){
        cout<<s;
        return;
    }
    cout<<s<<" ";
    if(s<=0){
        c=0;
    }
    if(c==1){
        chk(s-5,n,c);
    }
    else{
        chk(s+5,n,c);
    }
}

int main() {
	lint t;
	cin>>t;
	while(t--){
	    lint n;
	    cin>>n;
	    cout<<n<<" ";
	    chk(n-5,n,1);       // First argument -- the current no. of sequence, N -- original no., 1 -- to denote whether we have to move forward or back.
	    cout<<endl;
	}
	return 0;
}
