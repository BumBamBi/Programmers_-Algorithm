#include <iostream>
#include <algorithm>

using namespace std;

bool condition(char a, char b){
    return a>b;
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;
    // -------------------------------

    string str = to_string(N);
    sort(str.begin(), str.end(), condition);

    cout << str;
    return 0;
}