#include <stdio.h>
using namespace std;
/* 입력 첫째줄: 테스트 케이스 수 T
각 테스트 케이스는 6자리 숫자가 들어온다.

출력: 입력된 테스트 케이스가 Baby-Gin이면 Baby Gin, 아니면 Lose 출력
*/
void bubble_sort(int[], int);
void counting_sort(int[], int);

int main(void) {
    int T;
    scanf("%d",&T);
    while (T--) {
        int triplet = 0, run = 0;
        int input; //카드 입력
        int counts[10]={0,};

        scanf("%d", &input);
        for (int i=0;i<6;i++) {
            counts[(input%10)]++; //카드 개수
            input /= 10;
        }
        for (int i=0;i<10;i++) {
            if (counts[i]==3) { //triplet 확인
                triplet++;
                counts[i] -= 3;
                i--;
            }
            if (counts[i]>=1 && counts[i+1]>=1 && counts[i+2]>=1) { //run 확인
                run++;
                counts[i]--;
                counts[i+1]--;
                counts[i+2]--;
                i--;
            }
        }
        if (triplet+run==2)
            printf("Baby Gin\n");
        else
            printf("Lose\n");
    }
}

void bubble_sort(int arr[], int n) {
    int temp = 100; //Assume that numbers in array are smaller than 100
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1-i;j++) { // per loop, the largest number arranged in right
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void counting_sort(int arr[], int n) {
    /*
    카운팅 정렬
    - 정수나 정수로 표현할 수 있는 자료에 대해서만 적용 가능하다. (횟수를 기록하기 때문)
    - 속도가 빠르며 안정적이다.
    - 정렬된 배열을 각 숫자마다 그 개수만큼 거꾸로 채워간다고 생각하면 쉬움!
    */
   int counts[10]={0, }; // 0~9 사이의 숫자 카드
   int temp[6]={0, }; // 임의의 카드 6장
   int max = 0;

   for (int i=0;i<n;i++){
        counts[arr[i]]++;
        if (arr[i]>max)
            max = arr[i];
   }
   for (int i=1;i<=max;i++) {
       counts[i] = counts[i]+counts[i-1];
   }

   for (int i=n-1;i>=0;i--) {
       temp[--counts[arr[i]]] = arr[i];
   }

    for(int i=0;i<n;i++) {
        printf("%d", temp[i]);
        printf(" ");
    }
}