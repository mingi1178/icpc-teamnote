// a[p][k]: p의 부분 마스크 중 k번째 비트의 왼쪽 비트들이 p와 일치하는 것들의 집합의 원소들의 합 
void sos(int n){
    for(int i = 0; i < 1 << n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = a[i][j - 1];
            if(i & 1 << j - 1)a[i][j] += a[i - (1 << j - 1)][j - 1];
        }
    }
} // a[p][n]에 p의 부분집합의 합이 저장된다.