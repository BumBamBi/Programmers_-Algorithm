#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto e:commands){
        // iterator 이용해서 자르기
        // 타입 변수명(.begin(), .end())
        vector<int> temp(array.begin()+e[0]-1, array.begin()+e[1]);
        
        // 정렬
        sort(temp.begin(), temp.end());
        
        // 삽입
        answer.push_back(temp[e[2]-1]);
    }
    
    return answer;
}