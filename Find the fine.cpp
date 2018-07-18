/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/find-the-fine/0/?track=SP-Arrays%20and%20Searching
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
        lint n,d;
        cin>>n>>d;
        set<lint> s;
        for(lint i=0;i<n;i++){
            lint x;
            cin>>x;
            if(x%2 != d%2){
                s.insert(i);		// Inserting index of only those numbers for which penalty has to be calculated.
            }
        }
        lint pen = 0;
        for(lint i=0;i<n;i++){
            lint x;
            cin>>x;
            if(s.find(i)!=s.end()){
                pen+=x;				// Adding to penalty if the index is present in the set.
            }
        }
        cout<<pen<<endl;
    }
	return 0;
}
