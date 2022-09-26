#include<iostream>
#include<vector>
#include<algorithm>

int N, M;

using namespace std;

int main()
{

    cin >> N >> M;

    int matrix[N][N];

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        matrix[a][b]++;
        matrix[b][a]++;
    }

    

    return 0;
}

bool func(int[][] arr){
    
}