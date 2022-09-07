## vector

```c++
#include<vector>

vName.push_back();
vName.front();
vName.back();
vName.pop_back();
vName.empty();
vName.begin();
vName.end();
vName.erase(adr);          // adr(주소) = (vName.begin() - i)
vName.insert(adr, value);  // 해당 adr(주소) 바로 앞에 값을 삽입 ->
vName.at(index);           // index로 접근
vName[index];
vName.size();
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

// 선언
tuple<T, T, T ... > tupleName;
// 초기화
tuple<T, T, T ... > tupleName( , , , ....);

// 생성하기
make_tuple(10, 'x', "string");

// 값 가져오기
get<0>(tupleName);


```

### 함수 내 배열

(int a[][길이])

### 동적 선언

int\* arr = new int[10];
