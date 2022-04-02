#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool condition(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }else{
        return p1.second < p2.second;
    }
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    unordered_map<string, int> map;

    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        map.insert(make_pair(temp, temp.size()));
    }
    // -------------------------------

    vector<pair<string, int>> v;
    for(auto e:map){
        v.push_back(make_pair(e.first,e.second));
    }

    sort(v.begin(), v.end(), condition);

    for(auto e:v){
        cout << e.first << '\n';
    }

    return 0;
}