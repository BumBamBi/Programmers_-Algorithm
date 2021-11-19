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
        string temp_str = "";
        for(int i=0; i<len;i++){
            temp_str += to_string(v[i]);
        }

        if(temp_str.compare(pre_str) != 0){
            pre_str = temp_str;
            for(int i=0; i<len; i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
        }

    }while(next_permutation(v.begin(), v.end()));


    return 0;
}