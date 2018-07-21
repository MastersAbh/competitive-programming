/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/absolute-difference-1/0/?track=SP-Arrays%20and%20Searching
	Asked in : Jabong
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)


*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

bool adj_abs_one(lint n){		// Function to check if adjancent characters of a number have an abs difference of 1
    lint m=n%10;
    n/=10;
    while(n){
        lint x=n%10;
        if(abs(x-m)!=1){
            return false;
        }
        m=x;
        n/=10;
    }
    return true;
}


int main() {
	lint t;
	cin>>t;
	while(t--){
	    lint n,k;
	    cin>>n>>k;
	    vector<lint> v;
	    for(lint i=0;i<n;i++){
	        lint x;
	        cin>>x;
	        if(x<k){
	            v.push_back(x);				// storing only the numbers that are less than k
	        }
	    }
	    lint flag=0;
	    for(lint i=0;i<v.size();i++){
	        if(adj_abs_one(v[i])){
	            cout<<v[i]<<" ";
	            flag=1;
	        }
	    }
	    if(!flag){
	        cout<<-1;						// When no expected numbers found
	    }
	    cout<<endl;
	    
	}
}
