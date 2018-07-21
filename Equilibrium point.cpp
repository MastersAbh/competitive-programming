/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/equilibrium-point/0/?track=SP-Arrays%20and%20Searching
	Asked in : Amazon,Adobe
	
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
        lint sum=0;
        for(lint i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        lint left=0;
        lint right=sum;				// We maintain the right sum and left sum for every element
        for(lint i=0;i<n;i++){
            right-=a[i];
            if(left==right){
                cout<<i+1;			// Equilibrium point found when left sum equals right sum
                left=-1;
                break;
            }
            left+=a[i];
        }
        if(left>=0){
            cout<<-1;			// No equilibrium point
        }
        cout<<endl;
    }
	return 0;
}

