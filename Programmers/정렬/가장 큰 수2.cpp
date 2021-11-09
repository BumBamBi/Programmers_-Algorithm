#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 수를 합친 후에 비교
// 10 11 -> 1011, 1110 비교
// 1110이 더 크니 11이 앞으로가게 함.
bool condition(int _a, int _b){
    return to_string(_a) + to_string(_b) > to_string(_b) + to_string(_a);
}

string solution(vector<int> numbers) {
    
    // 합쳤을 때 큰 수대로 정렬
    sort(numbers.begin(), numbers.end(), condition);
    
    // return 할 변수에 저장
    string ans = "";
    for(auto e:numbers){
        ans += to_string(e);
    }
    
    // 0000 인 경우 0으로 안나오기 때문에 조건을 더함
    if(ans[0] == '0'){
        return "0";
    }else{
        return ans;
    }
}