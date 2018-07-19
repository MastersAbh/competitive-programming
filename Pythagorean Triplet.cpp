/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0/?track=SP-Arrays%20and%20Searching
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
        set<lint> s;
        lint a[n];
        for(lint i=0;i<n;i++){
            lint x;
            cin>>x;
            a[i]=x*x;					// storing the squares of all numbers in a set.
            s.insert(a[i]);
        }
        lint d=0;
        for(lint i=0;i<n;i++){
            for(lint j=i+1;j<n;j++){
                if(s.find(a[i]+a[j])!=s.end()){		// Finding if sum of two squares is also present in the set to find a pythagorean triplet.
                   // cout<<a[i]<<" "<<a[j]<<endl;
                    d=1;
                    break;
                }
            }
            if(d){
                break;
            }
        }
        if(d){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
	return 0;
}
