#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의가 끝나는 시간으로 오름차순 정렬
// 언제 시작하든, 빨리 끝나는 경우부터 이용하는 것이 가장 많이 이용 가능함
bool condition(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<pair<unsigned int, unsigned int>> v;

    for(int i=0; i<N; i++){
        unsigned int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    // -------------------------------

    sort(v.begin(), v.end(), condition);

    int result = 1;
    unsigned int end_time = v[0].second;
    for(int i=1; i<N; i++){
        if(v[i].first >= end_time){
            end_time = v[i].second;
            result += 1;
        }
    }
    cout << result;

    return 0;
}