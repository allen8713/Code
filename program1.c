#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N (int)1e5 + 5
#define M (int)1e2 + 5

int main(){
    int n, m, mode;
    int num;
    int digit_per_num;
    int ans[N];
    int cnt = 0;
    char cur_num[M];
    
    char inp_str[N];
    char matrix[M][M];
    scanf("%d", &mode);

    if(mode == 0){
        scanf("%d %d", &n, &m);
        scanf("%s", &inp_str);

        digit_per_num = strlen(inp_str) / n;
        for(int k = 0; k < strlen(inp_str); k += digit_per_num){
            strncpy(cur_num, inp_str + k, digit_per_num);
            ans[cnt++] = atoi(cur_num);
        }
        for(int k = 0; k < n; k++){
            strncpy(cur_num, inp_str + k * digit_per_num, digit_per_num);
            ans[cnt++] = atoi(cur_num);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                num = (int)inp_str[i] - 48;
                if(j == i) printf("1 ");
                else if(j == n) printf("%d", ans[i]);
                else printf("0 ");
            }
            printf("\n");
        }

        for(int i = 0; i < n; i++){
            printf("num = %d ",ans[i]);
        }
    }
    else if(mode == 1){
        scanf("%d", &n);
        fflush(stdin);
        for(int i = 0; i < n; i++){
            fgets(matrix[i], M, stdin);
        }
        
        for(int i = 0; i < n; i++){
            printf("%s",matrix[i]);
        }
    }

    return 0;
}