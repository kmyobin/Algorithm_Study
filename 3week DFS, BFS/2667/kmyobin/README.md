## Info
<a href="https://www.acmicpc.net/problem/2667" rel="nofollow">2667 단지번호붙이기</a>

## 풀이
`BFS`로 풀었다.

단지수도 풀력하고, 각 단지에 속하는 집의 수도 출력해야 한다.

따라서 단지수는 `ans`에 담고, 각 단지에 속하는 집의 수는 `vector<int> B`에 담았다. 대신 오름차순으로 정렬해야 하므로 B를 `오름차순 정렬`하였다. 

나머지는 다른 문제에서 구현한 `BFS` 코드와 동일하다. 

## 마무리
`BFS`에 대해 알게된 시간이었다.
