# 알고리즘 복잡도 (Big-O)

## Big-O 표기법
주어진 함수에서 엄밀한 점근석 상한을 나타내는 점근석 표기법
* 상수는 모두 제거한다.
* 가장 증가율이 높은 수식만 남긴다.

#### 공간 복잡도
알고리즘을 실행할 때 필요한 메모리

### 함수 복잡도
* f(n) = 4
* f(n) = 2n + 3
* f(n) 3n^2 + n + 5
* f(n) = 4n + log(n) + 3

### 코드의 시간/공간 복잡도
#### 예제 1
~~~java
boolean isFirstTwoMatch(int[] elements) {
    return elements[0] == elements[1];
}
~~~
시간 복잡도: 배열을 순회하지 않고 인덱스로 바로 접근하기 때문에 **O(1)**이 된다.

공간 복잡도: 배열의 크기와 상관 없이 고정적인 인덱스에 접근하기 때문에 **O(1)**이 된다.

#### 예제 2
~~~java
int sum(int[] elements) {
    int sum = 0;
    for (int number : elements) {
        sum += number;
    }
    return sum;
}
~~~
시간 복잡도: 주어진 배열에 따라 순회하는 횟수가 달라지기 때문에 **O(n)**이 된다.

공간 복잡도: 추가적으로 사용하는 변수는 sum 하나이기 때문에 **O(1)**이 된다.

#### 예제 3
~~~java
int factorial(int number) {
    if (number <= 2) {
        return number;
    }
    return number * factorial(number - 1);
}
~~~
시간 복잡도: 반복문이 없지만, 함수가 재귀적으로 n번 호출되기 때문에 **O(n)**이 된다.

공간 복잡도: 재귀함수가 호출될 때마다 스택에 쌓이기 때문에 **O(n)**이 된다.

#### 예제 4
~~~java
int findNumber(int numberToFind, int[] sortedNumbers) {
    int low = 0;
    int high = sortedNumbers.length - 1;
    int index = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int midNumber = sortedNumbers[mid];
        if (midNumber < numberToFind) {
            low = mid + 1;
        } else if (midNumber > numberToFind) {
            high = mid - 1;
        } else if (midNumber == numberToFind) {
            index = mid;
            brea;
        }

        return sortedNumbers[index];
    }
}
~~~
시간 복잡도: 한번 순회할 때마다 절반씩 제외가 되기 때문에 **O(logN)**이된다.

공간 복잡도: 변수를 추가로 네개만 사용하기 때문에 **O(1)**이 된다.


## 퀴즈 1) 유일한 숫자 찾기
numbers라는 int형 배열이 있다. 해당 배열에 들어있는 숫자들은 오직 한 숫나즐 제외하고는 모두 두 번씩 들어있다. 오직 한 번만 등장하는 숫자를 찾는 코드를 작성하라.


### 해결 1. List 사용
List를 만들고 배열에 있는 숫자를 순회하면서 해당 숫자가 List에 없으면 넣고 있다면 제거한다. 결과적으로 유일한 숫자 하나만 남게 된다.

~~~java
int solution(int[] numbers) {
    List<Integer> list = new ArrayList<>();
    for (int num : numbers) {
        if (list.contains(num)) {
            list.remove(num);
        } else {
            list.add(num);
        }
    }
    return list.get(0);
}
~~~

시간 복잡도: 배열 순회 O(n) * contains 함수 실행 O(n) = O(n^2)

공간 복잡도: 배열의 길이(n)만큼 list의 길이도 생성된다. O(n)

### 해결 2. Map 사용
Map을 사용해서 배열에 들어있는 숫자를 key, 숫자의 등장 횟수를 값으로 저장한다. 따라서 값이 1인 키 값을 찾아 리턴한다.
~~~java
int solution(int[] numbers) {
    Map<Integer, Integer> numbersMap = new HashMap<>();

    for (int num : numbers) {
        numbersMap.put(num, numbersMap.getOrDefault(num, 0) + 1);
    }

    for (int num : numbers) {
        if (numbersMap.get(num) == 1) {
            return num;
        }
    }
}
~~~

시간 복잡도: 순회를 n만큼 두 번한다. O(n) + O(n) 따라서 O(n)이 된다.

공간 복잡도: 배열의 길이(n)만큼 Map의 길이가 정해진다. O(n)

### 해결 3. XOR 비트 연산자 사용
같은 값끼리 XOR 연산을 하면 0이 되므로 유일한 숫자의 값만 남는다.

~~~java
int solution(int[] numbers) {
    int uniqueNum = 0;
    for (int num : numbers) {
        uniqueNum ^= num;
    }
    return uniqueNum;
}
~~~

시간 복잡도: 배열의 길이만큼 순회한다. O(n)

공간 복잡도: 변수를 하나만 사용한다. O(1)