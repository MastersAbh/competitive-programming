/*
	Problem Statement : https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0/?track=SP-Arrays%20and%20Searching
	Asked in : Amazon, Flipkart
	
	Code By:
	Abhinav,
	CSE, NIT P
	(Masters_Abh on codechef, codeforces, hackerrank and Spoj)


*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

map<lint,vector<char> > m;
void chk(lint a[],lint k,lint n,string s){			// Idea is to use a map storing chars for each no. and then use recursion to print all possible strings
    if(k==n){										// resulting from the characters of the input numbers in their order.
        cout<<s<<" ";
        return;
    }
    for(lint i=0;i<m[a[k]].size();i++){
        chk(a,k+1,n,s+m[a[k]][i]);
    }
}

int main() {
    
    lint t;
    cin>>t;
    lint x=2;
    char s='a';
    while(x<10){
        lint l=3;
        if(x==7 || x==9){
            l=4;
        }
        for(lint i=0;i<l;i++){
            m[x].push_back(s);
            s++;
        }
        x++;
    }
    while(t--){
        lint n;
        cin>>n;
        lint a[n];
        for(lint i=0;i<n;i++){
            cin>>a[i];
        }
        string h="";
        chk(a,0,n,h);
        cout<<endl;
    }
    return 0;
}
