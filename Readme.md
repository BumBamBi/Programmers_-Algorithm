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
v.insert(adr, value);  // 해당 adr(주소)에 값이 있도록 삽입    // 123 + insert(begin()+1, 0) => 1023 // v.insert(v.begin(), value); <- push_front()와 동일
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

map : 키-값으로 정의 된 STL. 중복을 허용하지 않음
set : 집합. 중복되지 않는 유일 값을 저장하는 STL

### map
```c++
// 정의/선언
// ------------------
#include <map>
// 기본적으로 map은 오름차순임
map<key, value> mymap;

// 내림차순으로 정의하고 싶다면
map<key, value, greater> mymap;


// 찾기
// ------------------
mymap.fine(KEY) // 값을 찾지 못한다면 map의 end()를 반환

// if문 활용
if(mymap.find("KEY") != mymap.end()){
    // 값이 있다는 것
}

// for문 활용
for(auto e:mymap){
    // first와 second로 접근 가능
    cout << e.first << endl;
    cout << e.second << endl;
}

// 삽입
// ------------------
mymap.insert({KEY,VALUE});

// 삭제
// ------------------
mymap.erase(주소);  // mymap.erase(mymap.begin() + a);
mymap.erase(KEY);   // mymap.erase(KEY);
mymap.clear();
```

### set

```c++
정의/선언
// ------------------
#include <set>
// 기본적으로 set 오름차순임
set<T> myset;
set<pair<T,T>> myset; // pair도 가능
set<T> set2(set1);      // set1을 복사해서 set2에 저장

// 내림차순으로 정의하고 싶다면?

// 찾기
// ------------------
myset.fine(Value);  // 값을 찾지 못한다면 set의 end()를 반환

// if문 활용
if(myset.find(Value) != myset.end()){
    // 값이 있다는 것
}

// for문 활용
for(auto e:myset){
    // 어떻게 확인해야할지 체크
}

for(auto iter = myset.begin(); iter != myset.end(); iter++){
    // 어떻게 확인해야하지 체크
}

// 삽입
// ------------------
myset.insert(Value);
myset.insert(주소, Value);

// 삭제
// ------------------
myset.erase(주소);      // myset.erase(myset.begin() + a);
myset.erase(Value);     // myset.erase(KEY);
myset.clear();
```

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
public:
    
}

class compare{
public:
    bool operator()(T a, T b){
        return a. < b.;
    }
};

priority_queue<T, vector<T>> pq; // 기본 최대힙(greater<T>)
priority_queue<T, vector<T>, less<T>> pq; // 최소힙

priority_queue<T, vector<T>, compare> pq; // 사용자 조건

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

## toupper / tolower
한글자 단위로 대소문자 변환

## upper_bound / lower_bound
특정 값 초과 / 이하인 숫자가, 몇번째 인덱스에서 처음 시작하는지 확인(오름차순)

``` c++
vector<int> vec;
vec.push_back(0);
vec.push_back(1);
vec.push_back(2);

upper_bound(vec.begin(), vec.end(), 1); // 1;
lower_bound(vec.begin(), vec.end(), 1); // 0;
```
-> 두개를 조합하여 n~m의 숫자 개수 확인 가능