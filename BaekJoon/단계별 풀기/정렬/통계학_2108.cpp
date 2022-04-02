#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<int> v;
    double sum = 0;
    unordered_map<int, int> m;

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        
        // 산수평균 계산을 위한 sum
        sum += temp;
        
        // 최빈값 계산을 위한 map 추가
        m.insert(make_pair(temp, 0));
    }
    // -------------------------------

    // 산술평균
    cout << round(sum/N) << '\n';

    // 중앙값
    sort(v.begin(), v.end());
    cout << v[N/2] << '\n';

    // 최빈값
    for(auto e:v){
        m[e] += 1;
    }

    // 최빈값 구하기
    int most_freq = -1;
    for(auto e:m){
        if(e.second > most_freq){
            most_freq = e.second;
        }
    }

    // 최빈값이 아닌것들 제거
    unordered_map<int, int> temp = m;
    for(auto e:temp){
        if(e.second != most_freq){
            m.erase(e.first);
        }
    }

    if(m.size() > 1){
        // 최빈값이 같은 것 중 가장 작은것 삭제
        m.erase(min_element(m.begin(), m.end()));
    }
    
    // 최빈값 중 가장 작은 수 출력
    cout << (*min_element(m.begin(), m.end())).first << '\n';

    // 범위
    int min_idx = *min_element(v.begin(), v.end());
    int max_idx = *max_element(v.begin(), v.end());
    
    cout << max_idx-min_idx << '\n';

    return 0;
}