#include <iostream>
#include <vector>

using namespace std;

// 최대 입력 개수 + 1
#define MAX 41

// 값을 메모이제이션 할 벡터
vector<pair<int, int>> v(MAX, make_pair(0,0));

// 메모이제이션 한 값이 있으면, 연산하지 않고 대체해서 출력
pair<int, int> fibo(int n) {
    if(n == 0){
        return make_pair(1,0);
    }else if(n==1){
        return make_pair(0,1);
    }else{
        if(v[n] == make_pair(0,0)){
            pair<int, int> temp_1 = fibo(n-1);
            pair<int, int> temp_2 = fibo(n-2);
            v[n] = make_pair(temp_1.first+temp_2.first, temp_1.second+temp_2.second);
            return v[n];
        }else{
            return v[n];
        }        
    }
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;


    vector<int> input_v;
    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        input_v.push_back(input);
    }
    // -------------------------------

    for(auto e:input_v){
        v[e] = fibo(e);
        cout << v[e].first << ' ' << v[e].second << '\n';
    }

    return 0;
}