#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_set>

using namespace std;

// 중복을 허용하지 않는 set 생성
unordered_set<int> myset;

// 소수를 구하는 함수
bool isPrime(int n){
    if(n < 2){
        return false;
    }

    for(int i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void myrecursive(string s){

    while(true){
        // 소수면 set에 추가 (int형으로 변경했기 때문에 011 과 11은 동일 취급되어 중복x)
        if(isPrime(stoi(s))){
            myset.insert(stoi(s));
        }

        // next_permutation을 이용하여 모든 순열을 구함
        // 모든 순열을 만든 후, false가 return 되면 while문 탈출
        if(next_permutation(s.begin(), s.end()) == false){
            break;
        }
    }
    
    // 지금까지의 과정으로 해당 string의 조합으로 가능한 모든 소수를 구함.

    string temp = s;

    // string의 모든 숫자를 하나씩 제거 후 다시 recursive 함수 실행
    // ex) 123 -> 23, 13, 12
    //      23 -> 3, 2
    //      13 -> 3, 1
    //      12 -> 2, 1
    for(int i=0; i<s.length(); i++){
        if(s.length()>1){
            myrecursive(temp.erase(i,1));
            temp = s;
        }        
    }
    return;
}

int solution(string numbers) {
    
    // next_permutation를 사용하기 위해 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    // 재귀함수
    myrecursive(numbers);

    int answer = myset.size();
    return answer;
}