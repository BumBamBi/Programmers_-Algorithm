## vector

```c++
#include<vector>

vector<T> v;
vector<pair<int, int>> v;
vector<tuple<int, int, T, T>> v;

v.push_back();
v.front();
v.back();
v.pop_back();
v.empty();
v.begin();
v.end();
v.erase(adr);          // adr(주소) = (v.begin() - i)
v.insert(adr, value);  // 해당 adr(주소)에 값이 있도록 삽입    // 123 + insert(begin()+1, 0) => 1023
v.at(index);           // index로 접근
v[index];
v.size();
```

## algorithm

```c++
#include <altorithm>

bool condition(T a1, T a2){ // 앞, 뒤 라고 생각하고
    return a1 < a2;         // 앞에보다 뒤에가 더 크니, 오름차순
}

sort(v.begin(), v.end(), condition);
```

## map/set

## stack/queue

### stack

- push()
- pop()
- top()

### queue

- push()
- pop()
- front()
- back()



### priority_queue

```c++
class T{

}

class compare{
    operator()(T a, T b){
        // 기존 compare과 반대
        return a < b
    }
}

priority_queue<T, vector<T>, less<T>> pq;   // default  - 내림차순 (최대힙)
priority_queue<T, vector<T>, greater<T>> pq;
priority_queue<T, vector<T>, compare> pq;
```

- push()
- pop()
- top()

### tuple

```c++
#include <tuple>
// 변수 선언
tuple<T, T, T ... > tupleName;

// 선언과 초기화
tuple<T, T, T ... > tupleName( , , , ....);

// 튜플 생성하기2
tupleName = make_tuple(10, 'x', "string");

// 값 가져오기1
cout << get<index>(tupleName);

cout << get<0>(tupleName);
cout << get<1>(tupleName);
cout << get<2>(tupleName);

// 값 가져오기2
int x;
string str1, str2;
tie(x,str1,str2) = tupleName;

// 투플 값 바꾸기
swap(tuple1, tuple2);

```

### 함수 내 배열

(int a[][길이])

### 동적 선언

int\* arr = new int[10];
