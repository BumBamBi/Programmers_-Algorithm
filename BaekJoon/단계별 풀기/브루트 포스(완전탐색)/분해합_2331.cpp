#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

int add_all_digit(int n){

    string str = to_string(n);

    vector<int> vec;
    for(auto e:str){
        vec.push_back(e-'0');
    }

    return accumulate(vec.begin(), vec.end(), 0);
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;
    // -------------------------------

    int result = 0;

    for(int i=1; i<N; i++){
        if( i + add_all_digit(i) == N){
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}