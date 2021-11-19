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

    vector<string> v;
    for(int i=1; i<=N; i++){
        v.push_back(to_string(i));
    }


    string pre_str = "";
    for(int i=0; i<len; i++){
        pre_str += v[i];
        cout << v[i] << ' ';
    }
    cout << '\n';

    do{
        string temp_str = "";
        for(int i=0; i<len; i++){
            temp_str += v[i];
        }
        if(pre_str.compare(temp_str) != 0){
            for(int i=0; i<len; i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
            pre_str = temp_str;
        }
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}