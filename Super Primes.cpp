/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/super-primes/0/?track=SP-Arrays%20and%20Searching
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)


*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
#define m 10900001
int main() {
	lint t;
	cin>>t;
	bitset<m> a;          // To save space, we use bitset.
	a[0]=1;
	a[1]=1;
	vector<lint> s;
	lint l=1;
	for(lint i=2;i*i<m;i++){        // Sieve of Eratosthenes.
	    if(a[i]==0){
	        for(lint j=2*i;j<m;j+=i){
	            a[j]=1;
	        }
	    }
	}
	for(lint i=3;i<m;i++){
	    if(a[i]==0 && a[i-2]==0){   
	        s.push_back(i);       // Adding all the super primes to a vector.
	    }
	}
	
	while(t--){
	    lint n;
	    cin>>n;
	    vector<lint > :: iterator it;
	    lint c=upper_bound(s.begin(),s.end(),n)-s.begin();    // Finding the index, and hence, the numner of super primes below N.
	    cout<<c<<endl;
	}
	return 0;
}
