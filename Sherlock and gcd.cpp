/*
	Problem Statement : https://www.hackerrank.com/challenges/sherlock-and-gcd/problem?h_r=internal-search
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codeforces, hackerrank and Spoj)


*/

#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define f(x) for(lint i=0;i<x;i++)
#define fj(x) for(lint j=0;j<x;j++)
#define mod 1000000007
#define F first
#define S second
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

lint gcd(lint a,lint b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}


int main(){
    faster;
    lint t;
    cin>>t;
    while(t--){
        lint n;
        cin>>n;
        lint a[n];
        cin>>a[0];
        lint y=a[0];
        for(lint i=1;i<n;i++){
            cin>>a[i];
            y=gcd(y,a[i]);
        }
        if(y==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
