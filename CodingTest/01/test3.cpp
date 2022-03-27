#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool condition(vector<int> a, vector<int> b){
    return a[0] > b[0];
}

vector<int> solution(vector<vector<int>> skills, int boss) {
    vector<int> answer;

    // 내림차순 정렬
    sort(skills.begin(), skills.end(), condition);

    // 잡을 수 있는 적인지 확인
    int totalDamage = 0;
    for(int i=0; i<skills.size(); i++){
        totalDamage += skills[i][0] * skills[i][1];
    }
    // 잡을 수 없다면 -1 리턴하고 끝
    if(totalDamage < boss){
        answer.push_back(-1);
        return answer;
    }

    // 잡을 수 있는 적이라면 -------------------------------
    int typeCnt = 0;
    int useCnt = 0;

    // 스킬을 전부 사용하면 나오는 데미지
    int damageCycle = 0;
    // 사용할 수 있는 스킬 횟수
    int totalSkillsCnt = 0;
    for(int i=0; i<skills.size(); i++){
        damageCycle += skills[i][0];
        totalSkillsCnt += skills[i][1];
    }

    // 스킬을 전부 사용해도 체력이 남는 적이라면,
    if(boss >= damageCycle){
        cout << "1" << endl;
        // 스킬 종류는 전부
        typeCnt = skills.size();
        useCnt = skills.size();

        // 반복하면서 boss 체력 깎기
        boss -= damageCycle;
        for(int i = 0; i<totalSkillsCnt; i++){
            if(boss <= 0){
                break;
            }

            // 스킬을 사용할 수 있다면,
            if(skills[i%skills.size()][1] > 1){
                skills[i%skills.size()][1]--;
                boss -= skills[i%skills.size()][0];
                useCnt++;
            }
        }
    }
    // 스킬을 최적으로 사용해야하는 적이라면,
    else{
        cout << "2" << endl;
        bool selected[skills.size()];
        int idx = skills.size()-1;

        // 작은 것부터 먼저 써보고
        for(int i=skills.size()-1; i>=0; i--){
            boss -= skills[i][0];
            skills[i][1]--;
            useCnt++;
            typeCnt++;

            selected[skills.size()-i] = true;

            if(boss <= 0){
                break;
            }
        }
        // 많은 것을 다시 쓰기
        if(boss > 0){
            for(int i=0; i<skills.size(); i++){
                if(skills[i][1] > 0){
                    boss -= skills[i][0];
                    skills[i][1] --;
                    useCnt++;
                    if(!selected[i]){
                        typeCnt++;
                    }
                }
                
            }
        }
        
    }
    
    answer.push_back(typeCnt);
    answer.push_back(useCnt);
    return answer;
}