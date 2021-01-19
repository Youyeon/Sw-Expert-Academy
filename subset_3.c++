#include <stdio.h>
/* 입력 첫째줄: 테스트 케이스 N
각 N줄: 테스트 케이스; 집합에 포함된 원소의 개수, 원소들
*/

int main(void) {
    int N;
    scanf("%d", &N);
    while (N--) {
        int flag = 0;
        int elements[100]={0, };
        int e; // number of element
        scanf("%d", &e);
        for (int i=0;i<e;i++) {
            scanf("%d", &elements[i]);
        }
        for (int i=1;i<(1 << e);i++) { //부분집합 개수만큼 반복
            int sum = 0; //부분집합의 합
            for (int j=0;j<e;j++) {
                if (i & (1 << j))
                    sum += elements[j];
            }
            if (sum==0){
                flag=1;
                break;
            }
        }
        if (flag)
            printf("True");
        else
            printf("False");
    }
}