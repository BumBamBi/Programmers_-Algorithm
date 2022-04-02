#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool condition(vector<string> v1, vector<string> v2){
    if(v1[0] == v2[0]){
        return stoi(v1[2]) < stoi(v2[2]);
    }else{
        return stoi(v1[0]) < stoi(v2[0]);
    }
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    
    vector<vector<string>> v;

    for(int i=0; i<N; i++){
        string age;
        string str;
        cin >> age >> str;

        vector<string> temp_v;
        temp_v.push_back(age);
        temp_v.push_back(str);
        temp_v.push_back(to_string(i));
        v.push_back(temp_v);
    }
    // -------------------------------

    sort(v.begin(), v.end(), condition);

    for(auto e:v){
        cout << e[0] << ' ' << e[1] << '\n';
    }

    return 0;
}