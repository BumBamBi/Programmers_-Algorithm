#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int all_tiles = brown + yellow;

    // 예측한 brown, yellow 타일의 개수
    int prediction_brown;
    int prediction_yellow;
    int row;

    // 9 = 1*9 3*3 9*1 이라서 [1,9] 와 [9,1] 이 중복됨. 따라서 sqrt로 중복이 안되도록 함.
    for(int col=1; col<=sqrt(all_tiles); col++){
        if(all_tiles%col == 0){
            row = all_tiles/col;
            
            // 사각형 일때 테두리 타일 개수와 내부 타일 개수 구하는공식
            prediction_brown = row * 2 + ((col-2) * 2);
            prediction_yellow = (row-2) * (col - 2);

            // 예측값과 실제 값이 맞으면 정답
            if(prediction_brown == brown && prediction_yellow == yellow){
                vector<int> answer;
                answer.push_back(row);
                answer.push_back(col);
                return answer;
            }
        }
    }
}