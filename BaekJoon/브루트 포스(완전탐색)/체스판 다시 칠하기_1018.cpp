#include <iostream>
#include <vector>

using namespace std;

int min_one_table(vector<vector<char>> v, int x, int y){
    
    char table[2] = {'W', 'B'};
    int check_BW_cnt = 0;

    // W 시작인 경우 틀린 칸
    int wrong_1 = 0;
    // B 시작인 경우 틀린 칸
    int wrong_2 = 0;
    

    for(int i=y; i<y+8; i++){
        for(int j=x; j<x+8; j++){
            if(v[i][j] == table[(check_BW_cnt%2)]){
                wrong_2 += 1;
            }else{
                wrong_1 += 1;
            }
            check_BW_cnt += 1;
        }
        // 줄이 바뀔때마다 엇갈리도록 한번 더 + 1
        check_BW_cnt += 1;
    }

    if(wrong_1 < wrong_2){
        return wrong_1;
    }else{
        return wrong_2;
    }

}

int main(){

    // 입력 --------------------------
    int x, y;
    cin >> y >> x;
    vector<vector<char>> v;

    vector<char> temp_v;

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            char temp;
            cin >> temp;
            temp_v.push_back(temp);
        }
        v.push_back(temp_v);
        temp_v.clear();
    }
    // -------------------------------


    int min = 999;

    // 8x8 이 가능한 시작점(x,y)를 찾기
    for(int i=0; i<=y-8; i++){
        for(int j=0; j<=x-8; j++){
            // 가능하다면 해당 8x8에서 수정 최소개수를 구하기
            int temp = min_one_table(v, j, i);
            if(temp < min){
                min = temp;
            }
        }
    }

    cout << min;

    return 0;
}