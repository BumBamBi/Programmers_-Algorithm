#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool is_unique(vector<int> v, int n){
    int cnt = 0;
    for(auto e:v){
        if(e == n){
            cnt += 1;
        }
        if(cnt >= 2){
            return false;
        }
    }
    return true;
}

string solution(vector<vector<int>> scores) {
    
    string answer = "";
    
    // scores를 복사한 my_vec 생성
    vector<vector<int>> my_vec(scores);
    
    // 처리하기 쉽도록 세로합 형식을 가로합 형식으로 변경
    for(int i=0; i<scores.size(); i++){
        for(int j=0; j<scores.size(); j++){
            my_vec[i][j] = scores[j][i];
        }
    }
    
    for(int i=0; i<my_vec.size(); i++){
        // 특정인이 받은 점수중 최소, 최대값을 구함 
        int min_value = *min_element(my_vec[i].begin(), my_vec[i].end());
        int max_value = *max_element(my_vec[i].begin(), my_vec[i].end());
        
        // 자기 자신을 평가한 점수가 최소, 최대값이라면
        if(my_vec[i][i] == min_value || my_vec[i][i] == max_value){
            // 자기 자신을 평가한 점수가 유일한 점수라면
            if(is_unique(my_vec[i], my_vec[i][i])){
                my_vec[i].erase(my_vec[i].begin()+i);
            }
        }
        
        // 평균 구하기
        double avg = accumulate(my_vec[i].begin(), my_vec[i].end(), 0.0) / my_vec[i].size();

        // 학점 조건
        if(avg >= 90){
            answer += 'A';
        }else if(avg >= 80){
            answer += 'B';
        }else if(avg >= 70){
            answer += 'C';
        }else if(avg >= 50){
            answer += 'D';
        }else{
            answer += 'F';
        }
    }
    return answer;
}