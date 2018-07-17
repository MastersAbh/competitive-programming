/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/find-the-closest-number/0/?track=SP-Arrays%20and%20Searching
	
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
        lint l=0;
        lint r=n-1;
        lint mn = 100010;
        lint num;
        while(l<=r){					// A sweet implementation of binary search.
            lint mid = l + (r-l)/2;
            if(a[mid]>k){
                r=mid-1;
            }
            else if(a[mid]<=k){
                l=mid+1;
            }
            if(mn>abs(a[mid]-k)){
                mn=abs(a[mid]-k);
                num=a[mid];
            }
            else if(mn==abs(a[mid]-k)){	// For accounting for the larger number in case of equal differences.
                num=max(num,a[mid]);
            }
        }
        cout<<num<<endl;
    }
	return 0;
}
