#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    // 직관적일 수 있도록 숫자로 변환 후, 벡터에 저장
    vector<int> numbers;
    
    for(auto e:number){
        numbers.push_back(e-'0');
    }
    
    // 1. 첫 자리를 가능한 큰 수로 선택하기
    
    // a) 앞자리부터, k번째 자릿수 중 가장 큰 수 찾기
    int max_num = *max_element(numbers.begin(), numbers.begin()+(k+1));
    
    // b) 앞자리부터, 가장 큰 수가 아니라면 삭제
    int removing_idx = 0;
    for(int i=0; i<k; i++){\
        if(numbers[i] != max_num){
            removing_idx += 1;
        }else{
            numbers.erase(numbers.begin(), numbers.begin()+removing_idx);
            k -= removing_idx;
            break;
        }
    }

    // 2. 앞 자릿수부터, 현재 숫자가 다음 숫자보다 작으면 삭제
    int pre_k;
    int start_idx = 1;
    do{
        pre_k = k;
        for(int index = start_idx; index<numbers.size(); index++){
            if(numbers[index-1] < numbers[index]){
                numbers.erase(numbers.begin()+(index-1));
                k -= 1;
                start_idx -= 1;
                break;
            }
            start_idx += 1;
        }
    }while(k > 0 & pre_k != k);
    // 3. 한번 다 삭제한 후, 아직 제거할 숫자가 남아있으면 다시 반복
    
    // 다 똑같은 경우 작은수부터 차례대로 지우기
    while(k>0){
        numbers.erase(min_element(numbers.begin(), numbers.end()));
        k -= 1;
    }
    
    // 4. 반환형에 맞게 리턴
    for(auto e:numbers){
        answer += (e+'0');
    }
    return answer;
}