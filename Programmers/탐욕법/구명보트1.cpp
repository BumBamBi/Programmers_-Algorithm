#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool condition(int a, int b){
    return a > b;
}


int solution(vector<int> people, int limit) {
    int answer = 0;
    
    bool isSelected[people.size()];
    
    for(int i=0; i<people.size(); i++){
        isSelected[i] = false;
    }
    
    sort(people.begin(), people.end(), condition);
    
    int N = people.size();
    int cnt= 0;
    int getPeople = 0;
    int minWieght = people[N-1];
    int start_idx = 0;
    int end_idx = N;
    
    while(getPeople < N){
        int sum = 0;
        int seatCnt = 0;
        for(int i=start_idx; i<end_idx; i++){
            if(sum + minWieght > limit){
                break;
            }
            if(!isSelected[i]){
                int curPersonWeight = people[i];
                if(sum + curPersonWeight <= limit){
                    isSelected[i] = true;
                    sum += curPersonWeight;
                    getPeople++;
                    seatCnt++;
                    
                    if(seatCnt == 2){
                        break;
                    }
                }
            }
        }
        
        // 시작점 잡기
        for(int i=start_idx; i<N; i++){
            if(!isSelected[i]){
                start_idx = i;
                break;
            }
        }
        // 끝점 잡기
        for(int i=end_idx; i>=0; i--){
            if(!isSelected[i-1]){
                end_idx = i;
                break;
            }
        }
        // minWieght 고치기
        minWieght = people[end_idx-1];
        
        cnt++;
    }
    
    
    return cnt;
}