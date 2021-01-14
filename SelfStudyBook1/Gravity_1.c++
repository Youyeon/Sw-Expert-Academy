#include <iostream>
using namespace std;
/* 입력 첫째줄: test cast 수 T
각 케이스의 첫째줄: 방의 가로 길이 N, 세로 길이 M
다음 줄: N개의 상자들이 쌓여 있는 높이 H

출력: 낙차가 가장 큰 값
*/

int main(void) {
    int T, N, M;
    cin >> T;
    while(T--) {
        int room[100][100]={0,};
        int H;
        int max = 0, idx = 0;
        int maxFallen = 0;
        cin >> N >> M;
        for (int i=0;i<N;i++){
            cin >> H;
            if (max<H) {
                max = H;
                idx = i;
            }
            for (int j=0;j<H;j++) {
                room[j][i]=1;
            }
        }
        for (int i=idx+1;i<N;i++) { //낙차 큰 값 계산
            if (room[max-1][i]!=1)
                maxFallen += 1;
    }
    cout << maxFallen;
    }
}
