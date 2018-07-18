/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/sort-in-specific-order/0/?track=SP-Arrays%20and%20Searching
	Asked in : Microsoft
	
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
	    multiset<lint, greater<lint> > odd;	// For descending order of odd numbers.
	    multiset<lint> even;				// Ascending order of even numbers.
	    for(lint i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i]%2==0){
	            even.insert(a[i]);
	        }
	        else{
	            odd.insert(a[i]);
	        }
	    }
	    multiset<lint, greater<lint> > :: iterator od;
	    multiset<lint> :: iterator ev;
	    for(od = odd.begin();od!=odd.end();++od){
	        cout<<*od<<" ";
	    }
	    for(ev = even.begin();ev!=even.end();++ev){
	        cout<<*ev<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
