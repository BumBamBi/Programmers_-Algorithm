#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(vector<int> nums)
{
    // 최대 가져갈 수 있는 수 N/2
    int half_nums = nums.size()/2;
    
    // 정렬
    sort(nums.begin(), nums.end());
    
    // 중복제거
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    // 중복되지 않는 요소들의 개수
    int unique_cnt = nums.size();

    // 최대 가져갈수 있는 수 vs 중복되지 않는 요소의 수
    // half_nums > unique_cnt 이라면 결과는 항상 unique_cnt
    return min(half_nums, unique_cnt);
}