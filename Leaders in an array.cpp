/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/?track=SP-Arrays%20and%20Searching
	Asked in : Payu
	
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
        multiset<lint> m;
        map<lint,lint> mm;
        for(lint i=0;i<n;i++){
            cin>>a[i];
            mm[a[i]]++;
            m.insert(a[i]);
        }
        for(lint i=0;i<n;i++){
            mm[a[i]]--;
            if(mm[a[i]]==0){
                m.erase(a[i]);
            }
            if(m.lower_bound(a[i])==m.end()){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    
	return 0;
}
