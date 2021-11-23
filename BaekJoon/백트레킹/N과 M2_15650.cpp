#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    // 입력 --------------------------
    int N, len;
    cin >> N >> len;
    // -------------------------------

    vector<int> v;
    for(int i=1; i<=N; i++){
        v.push_back(i);
    }

    string pre_str = "";
    for(int i=0; i<len;i++){
        pre_str += to_string(v[i]);
        cout << v[i] << ' ';
    }
    cout << '\n';

    do{
        bool is_print = true;
        int min_num = 1;
        string temp_str = "";
        for(int i=0; i<len;i++){
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
                for(int i=0; i<len; i++){
                    cout << v[i] << ' ';
                }
                cout << '\n';
            }
        }
        

    }while(next_permutation(v.begin(), v.end()));


    return 0;
}