#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define N 105
#define X 1000005
 
ll coin[N];
ll dp[X];
 
set<ll> coin_s;
 
int main(){
    ll n;
    ll sum;
    scanf("%lld %lld",&n,&sum);
    int i,j;
    for(i = 0; i < n; i++){
        scanf("%lld",&coin[i]);
        // coin_s.insert(coin[i]);
        // if(coin_s.count(j)) dp[j] = 1;
        //dp[coin[i]] = 1;
    }
    for(i = 0; i < n; i++){
        dp[coin[i]] += 1;
        for(j = 1; j <= sum; j++){
            if(j - coin[i] < 0) continue;
            if(dp[j - coin[i]]){
                dp[j] += dp[j - coin[i]] % MOD;
                dp[j] %= MOD;
            }   
        }
        dp[j] % MOD;
    }
    // for(i = 0; i <= sum; i++){
    //     printf("dp[%d] = %lld\n",i,dp[i]);
    // }
    printf("%lld\n",dp[sum]);
    return 0;
}