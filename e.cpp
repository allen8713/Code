#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> mp[100];
queue <ll> encode;
ll origin[100][100];
bool vstd[100][100];

void init(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            vstd[i][j] = false;
        }
    }
}

ll area = 0;
ll m;

bool touched = false;

void dfs(ll x, ll y){
    if(vstd[x][y]) return;
    //printf("vstd : (%lld, %lld)\n",x,y);
    vstd[x][y] = true;
    if(x == 0 || x + 1 == m || y == 0 || y + 1 == m){
        area = 0;
        touched = true;
        //return;
    }
    area++;
    
    if(x + 1 < m && origin[x + 1][y] == 0) dfs(x + 1, y);
    if(y + 1 < m && origin[x][y + 1] == 0) dfs(x, y + 1);
    if(x - 1 >= 0 && origin[x - 1][y] == 0) dfs(x - 1, y);
    if(y - 1 >= 0 && origin[x][y - 1] == 0) dfs(x, y - 1);
    
    return;
}

int main(){
    ll t;
    ll num;
    scanf("%lld",&t);
    while(t--){
        // printf("f_size = %d\n",encode.size());
        // while(!encode.empty()){
        //     //printf("aa\n");
        //     encode.pop();
        // }
        scanf("%lld",&m);
        while(scanf("%lld",&num)){
            if(num == -1) break;
            encode.push(num);
        }
        ll cnt = 0;
        ll now_cnt = encode.front();
        encode.pop();
        bool color = true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                
                if(now_cnt == 0){
                    color = !color;
                    now_cnt = encode.front() - 1;
                    encode.pop();
                    if(color) origin[i][j] = 0;
                    else origin[i][j] = 1;
                    continue;
                }

                if(color) origin[i][j] = 0;
                else origin[i][j] = 1;

                if(now_cnt > 1){
                    now_cnt--;
                }
                else if(now_cnt == 1){
                    now_cnt = encode.front();
                    if(!encode.empty()){
                        encode.pop();
                    }
                    color = !color;
                }
                
            }
        }
        init();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                area = 0;
                touched = false;
                if(!vstd[i][j] && origin[i][j] == 0){
                    dfs(i,j);
                    //printf("in\n");
                    if(!touched ) printf("%lld\n",area);
                }
                
            }    
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                printf("%lld",origin[i][j]);   // print the map
            }
            printf("\n");
        }
        
    }
    return 0;
}