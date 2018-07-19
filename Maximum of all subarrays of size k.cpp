/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?track=SP-Arrays%20and%20Searching
	Asked in : Amazon, Flipkart, DirectI
	
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
        lint n,k;
        cin>>n>>k;
        lint a[n];
        for(lint i=0;i<n;i++){
            cin>>a[i];
        }
        set<lint,greater<lint> > s; 	// Maintaining a set that stores the greatest element at the top.
        map<lint,lint> m;
        for(lint i=0;i<k;i++){
            m[a[i]]++;
            s.insert(a[i]);
        }
        cout<<*(s.begin())<<" ";
        for(lint i=k;i<n;i++){
            m[a[i]]++;				
            m[a[i-k]]--;
            if(m[a[i-k]]==0){
                s.erase(a[i-k]);		// erasing the element that is no more in the sequence
            }
            s.insert(a[i]);				// Adding the latest element of the sequence
            cout<<*(s.begin())<<" ";
        }
        cout<<endl;
    }
	return 0;
}
