#include<bits/stdc++.h>
using namespace std;
#define N (int)1e6 + 5

int dp[N] = {0};

int main(){
    for(int i = 1; i <= 9; i++){
        dp[i] = 1;
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",dp[n]);
    return 0;
}