#include <string>
#include <vector>
#include <math.h>
#include <array>

using namespace std;

string solution(int n) {
    
    // 3^자리수 만큼의 수가 나오므로
    // 3, 9, 27, ... 순으로 잘라서 구분함
    
    // 자리수 d
    int d = 0;
    
    // 자리수에 따른 최대 값
    int max_std = 0;
    
    // 자리수에 따른 최소 값
    int min_std = 0;
    
    while(1){
        if(n <= max_std){
            break;
        }else{
            d += 1;
            // 자리수에 따른 최소, 최대값을 구함
            // ex) 2자리 4~12
            max_std += pow(3,d);
            min_std += pow(3,d-1);
        }
    }
    cout << d << "자리" << endl;
    
    // 자리수에 따라 잘라낸 블록의 총 크기
    // ex) 2자리 4~12 이므로 9
    int block_size = max_std - min_std + 1;
    
    // n의 값을 자리수에 따른 덩어리의 index로 변환
    n = n - min_std;
    
    // 1. string에 이어 붙히기(실패)
    // 2. vector에 이어 붙히기(실패)
    // 3. array에 이어 붙히기(실패)
    string ans_string = "";
    
    int start_std = d-1;
    
    for(int i=0; i<d; i++){
        if(n < ((block_size/3) * 1)){
            // 블록을 3으로 나눈 가장 앞의 수는 1
            ans_string += '1';
        }
        else if(n < ((block_size/3) * 2)){
            // 블록을 3으로 나눈 가운데 수는 2
            ans_string += '2';
            // n의 index를 다음자리 수에 맞춰서 이동
            n -= pow(3, start_std-i);
        }
        else{
            // 블록을 3으로 나눈 마지막 수는 4
            ans_string += '4';
            // n의 index를 다음자리 수에 맞춰서 이동
            n -= (pow(3, start_std-i) * 2);
        }
        // 블록 사이즈 변경
        block_size /= 3;
    }
    
    return ans_string;
}