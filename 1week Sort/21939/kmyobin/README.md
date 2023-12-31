## Info
<a href="https://www.acmicpc.net/problem/21939" rel="nofollow">21939 문제 추천 시스템 Version 1</a>

## ?? 풀이
처음에는 `multimap`을 이용하여 풀었다. `multimap`은 `map`과 거의 동일하지만 `key값이 중복 가능하다`는 점에서 차이가 있다.

따라서 `key`값을 `난이도`, `value`를 `문제 번호`로 설정하여 풀었는데 시간 초과가 발생하였다. 검색해보니 `multimap`으로 풀었던 사람이 시간초과가 발생하여 `multiset`으로 바꿔서 풀었더니 성공했다고 하길래 나도 바꿨다. `multiset`은 value값이 중복되지 않는다. 

또 하나 달라진 점은 배열을 추가했다는 것이다. `recommend`와 `add` 기능은 `multimap`에서도 쉽게 구현할 수 있었으나 `solved` 기능을 구현할 때 시간초과가 발생했음을 유추했다. 딸서 `A[문제번호]`에 `난이도`를 넣어서 반복문 없이 바로 문제번호의 난이도에 접근할 수 있게 하였다. 문제 번호가 갱신될 수 있으나 난이도도 따라서 갱신되니 상관없다. 따라서 `난이도`라는 `key`값을 손쉽게 찾아 `find` 함수와 `erase` 함수를 이용하면 해당 value값을 제거할 수 있다.


## 마무리
`multiset`을 쓰다보니 이 문제는 `set`으로도 풀릴 것 같다. 다음에 해봐야겠다.