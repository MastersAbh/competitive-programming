#include<iostream>
using namespace std;

// O(NK),O(N)  can be optimised to O(N+K),O(N)
int ladders_topdowm(int n, int k, int dp[]){
    //base case
    if(n==0){
        return 1;
    }

    //lookup
    if(dp[n]!=0){
        return dp[n];
    }

    //recursive case
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(n>=i){
            ways += ladders_topdowm(n-i,k,dp);
        }
    }
    return dp[n] = ways;
}

int ladders_bottomup(int n,int k){
    int dp[100] = {0};
    dp[0] = 1;

    for(int i=1; i<=n; i++){ // dp[i] will store total ways if n were i 
        for(int j=1; j<=k; j++){
            if(i-j>=0){    //this is doing for not going to -ve value 
                dp[i] += dp[i-j];
            }
        }
    }

    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n];
}

//O(N+K),O(N)
// Observation 1 :- till k from 1 dp[i] is doubling
int ladder_Bottom_UP_optimised(int n, int k){
    int dp[100] = {0};

    dp[0] = dp[1] = 1;
    for(int i=2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;

    int dp[100] = {0};

    cout<<ladders_topdowm(n,k,dp)<<endl;
    cout<<ladders_bottomup(n,k)<<endl;
    cout<<ladder_Bottom_UP_optimised(n,k)<<endl;
    
    return 0;
}
