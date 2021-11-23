#include <iostream>
#include <vector>

using namespace std;

void func(int N, int M, vector<int> visited, int len) {
	// 마지막 출력단계
    if (len == M) {
		for(auto e:visited){
            cout << e << ' ';
        }
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
        visited.push_back(i);
		func(N, M, visited, len + 1);
        visited.pop_back();
	}
}

int main() {
	// 입력 --------------------------
    int N, M;
    cin >> N >> M;
    // -------------------------------

    vector<int> visited;

    func(N, M, visited, 0);

    return 0;
}