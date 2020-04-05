# Note for Online Judgement

Python:`>>> help(heap.heappushpop)`

## input

Python:
```Python
N, L = [int(i) for i in input().split()]
```

## heap

Python:
```Python
import heapq
a = [] # a[0] is min, for MaxHeap: store their opposites
for i in input().split():
    heapq.heappush(a, int(i))
# heapq.heappushpop: 
# Push item on the heap, then pop and return the smallest item from the heap.
```

C++:
```C++
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    priority_queue<node_t, vector<node_t>, greater<node_t> > q;
    q.emplace_back()
}
```

## math

Python:
```Python
import math
math.factorial(x)
math.fsum([1, 2, 3, 4])
math.gcd(x, y)
math.log(x[, base])
math.pi
math.pow(x, y) # x^y
```

## debug

If wrong output happens, try to find a simplest input data.
