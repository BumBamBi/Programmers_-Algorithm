## vector

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