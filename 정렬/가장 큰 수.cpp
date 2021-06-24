#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(int& _a, int& _b){
    string sa = to_string(_a);
    string sb = to_string(_b);

    // 두 수를 ab, ba 로 붙여서대소 비교
    string strcat1 = sa + sb;
    string strcat2 = sb + sa;

    // 오름차순 상태면 a >_ b 임.
    // return 이 false 면 변경x, true면 변경o
    return stoi(strcat1) > stoi(strcat2);
}

string solution(vector<int> numbers) {

    vector<int> my;
    for(auto e:numbers){
        my.push_back(e);
    }

    // condition 조건에 맞게 정렬
    sort(my.begin(), my.end(), condition);

    string answer;

    // answer에 값 입력
    for(auto e:my){
        for(int i=0; i<to_string(e).length(); i++){
            answer += to_string(e)[i];
        }
    }
    
    // 000 과 같은 경우 0으로 출력
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}