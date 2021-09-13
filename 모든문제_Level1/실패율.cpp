#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(pair<int, float> _a, pair<int, float> _b){
    // 실패율에 대한 내림차순 정렬
    if (_a.second > _b.second){
        return true;
    }
    // 실패율이 같은 경우에는 index에 대한 오름차순
    else if (_a.second == _b.second){
        return _a.first < _b.first;
    }else{
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    
    // <int, float> 형식을 가지는 벡터 생성 (<stage, 실패율>)
    vector<pair<int, float>> Stage_FiledValue(N);
    
    // 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수
    float ClearYet_cnt = 0;
    // 스테이지에 도달한 플레이어 수
    float Reached_cnt = stages.size();

    // 스테이지 개수만큼 반복하면서 동일한 값이 있으면 카운트
    for(int i=0; i<N; i++){
        // 동일한 값이면, 해당 스테이지를 도전중인 사람들의 수(ClearYet_cnt)
        ClearYet_cnt = count(stages.begin(), stages.end(), i+1);
        
        // 아무도 도달하지 못한 스테이지 유무 확인
        if(Reached_cnt != 0){
            // 실패율을 계산 후 대입
            Stage_FiledValue[i] = make_pair(i+1, ClearYet_cnt/Reached_cnt);
        }else{
            // 실패율을 0으로 설정
            Stage_FiledValue[i] = make_pair(i+1, 0);
        }
        
        // 이미 계산 완료한 플레이어를 제외하기 위함
        Reached_cnt -= ClearYet_cnt;
    }
    
    // 위 벡터를 실패율(second)에 대한 내림차순 내림차순 정렬함
    sort(Stage_FiledValue.begin(), Stage_FiledValue.end(), condition);
    
    
    // 결과를 저장할 벡터
    vector<int> answer;
    
    // 정렬된 벡터의 stage부분(first)을 차례대로 대입
    for(auto e:Stage_FiledValue){
        answer.push_back(e.first);
    }
    
    return answer;
}