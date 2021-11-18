#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }else{
        return p1.first < p2.first;
    }
} 

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    // -------------------------------

    sort(v.begin(), v.end(), condition);

    for(auto e:v){
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}