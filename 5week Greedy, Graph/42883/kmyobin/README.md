## Info
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/42883" rel="nofollow">42883 큰 수 만들기</a>


## 풀이
처음에는 `조합`을 떠올려 풀려고 했으나, `그리디 알고리즘`인 것을 감안하여 다시 생각해보았다.

`k`개를 제거하면 최종적으로 `number.length() - k`자릿수가 되므로 그것을 참고하였다.

`number.length() - k`자릿수가 되려면 `k + i`까지 접근해야하므로 for문을 그렇게 구성하였다.


## 마무리
`그리디 알고리즘`을 풀 때는 조금 더 쉽게 풀 수 있는지 끊임없이 고민해야겠다.