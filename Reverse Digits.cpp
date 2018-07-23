/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/reverse-digit/0/?track=SP-Recursion
	Asked in : MAQ Software
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

bool leading_zero;      // Keeps a track of whether the 0 is leading one.

void chk(lint n){
    if(n==0){
        return;
    }
    if(n%10!=0){
        leading_zero=false;
        cout<<n%10;
    }
    else{
        if(!leading_zero){
            cout<<0;
        }
    }
    n/=10;
    chk(n);
    
}

int main() {
    lint t;
    cin>>t;
    while(t--){
        leading_zero=true;
        lint n;
        cin>>n;
        chk(n);
        cout<<endl;
    }
	return 0;
}
