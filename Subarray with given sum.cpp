/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/?track=SP-Arrays%20and%20Searching
	Asked in : Visa,Google,Facebook,Amazon
	
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
        lint left=1,right=1,sum=a[0];		// Maintain left and right index of the range
        while(right<=n){
            if(sum>k){
                sum-=a[left-1];				// If the sum goes larger than expected value, shift a position from left
                left++;
            }
            else if(sum==k){
                cout<<left<<" "<<right;		// When the expected sum is found
                left=-1;
                break;
            }
            else{
                right++;
                if(right>n){				// Else, continue to shift the right index forward
                    break;
                }
                sum+=a[right-1];
            }
        }
        if(left!=-1){						// When no range is found for the expected sum
            cout<<-1;
        }
        cout<<endl;
    }
	return 0;
}
