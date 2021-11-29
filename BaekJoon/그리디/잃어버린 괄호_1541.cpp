#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    // 입력 --------------------------
    string s;
    cin >> s;
    // -------------------------------

    vector<int> v;
    vector<bool> oper(1, true);
    string temp = "";

    for(auto e:s){
        // 숫자라면
        if((e-'0') >= 0 && (e-'0') <= 9){
            temp += e;
        }else{
            v.push_back(stoi(temp));
            temp = "";
            if(e == '+'){
                oper.push_back(true);
            }else{
                oper.push_back(false);
            }
        }
    }
    v.push_back(stoi(temp));

    // -가 나온 이후는 전부 다 빼기
    // -가 한번이라도 나와다면 괄호를 통해 전부 -로 변경 가능
    int result = 0;
    bool flag = true;
    for(int i=0; i<v.size(); i++){
        if(oper[i] == false){
            flag = false;
        }

        if(flag){
            result += v[i];
        }else{
            result -= v[i];
        }
    }

    cout << result;

    return 0;
}