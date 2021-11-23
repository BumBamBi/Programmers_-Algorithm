#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    // 입력 --------------------------
    int N, M;
    cin >> N >> M;
    // -------------------------------

    // 값 저장
    vector<int> v;
    for(int i=1; i<=N; i++){
        v.push_back(i);
    }

    // 첫번째 순열 출력
    string pre_str = "";
    for(int i=0; i<M;i++){
        pre_str += to_string(v[i]);
        cout << v[i] << ' ';
    }
    cout << '\n';

    // 순열 출력(큰값만 뽑는 조건 추가)
    do{
        bool is_print = true;
        int min_num = 1;
        string temp_str = "";
        for(int i=0; i<M;i++){
            temp_str += to_string(v[i]);
            if(min_num > v[i]){
                is_print = false;
                break;
            }else{
                min_num = v[i];
            }
        }
        if(is_print){
            if(temp_str.compare(pre_str) != 0){
                pre_str = temp_str;
                for(int i=0; i<M; i++){
                    cout << v[i] << ' ';
                }
                cout << '\n';
            }
        }
    }while(next_permutation(v.begin(), v.end()));


    return 0;
}