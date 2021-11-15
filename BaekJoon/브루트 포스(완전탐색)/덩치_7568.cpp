#include <iostream>
#include <vector>

using namespace std;


int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<vector<int>> vec;
    for(int i=0; i<N; i++){
        vector<int> temp;
        int x, y;
        cin >> x >> y;
        temp.push_back(x);  // 무게
        temp.push_back(y);  // 키
        temp.push_back(1);  // 덩치 순위
        vec.push_back(temp);
    }
    // -------------------------------

    
    // 나보다 덩치가 큰사람이 있으면 순위가 하나씩 내려감
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if( i!=j && vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1]){
                vec[i][2] += 1;
            }
        }
    }

    // 출력
    for(int i=0; i<N; i++){
        cout << vec[i][2] << ' ';
    }

    return 0;
}