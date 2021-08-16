#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    
    vector<vector<int>> temp(board);
    
    // 쉽게 처리하기 위하기 위해 가로 방식으로 변경
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp.size(); j++){
            temp[i][j] = board[(board.size()-1)-j][i];
        }
    }
    
    // 값이 0인 경우 제거함
    for(int i=0; i<temp.size(); i++){
        while(!temp[i].empty() && temp[i].back() == 0){
            temp[i].pop_back();
        }
    }
    


    // 뽑은 인형을 모아둘 벡터 생성
    vector<int> backet;
    
    // 인형 옮기기
    for(auto e:moves){
        if(temp[e-1].empty()){
           continue; 
        }else{
            int new_doll = temp[e-1].back();
            temp[e-1].pop_back();
            
            // 기존 바구니의 마지막 인형과 새 인형이 동일한 인형인지 확인
            if(!backet.empty() && backet.back() == new_doll){
                // 동일하다면 제거 후 answer += 2
                backet.pop_back();
                answer += 2;
            }else{
                // 동일하지 않다면 추가
                backet.push_back(new_doll);
            }
        }
    }
    return answer;
}