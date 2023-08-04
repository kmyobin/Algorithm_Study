## Info
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/42840" rel="nofollow">42840 모의고사</a>


## 풀이
`Brute-Force` 문제이다.

수포자는 총 3명이 있는데, 이들이 쓴 정답을 각각 다른 `vector<int>`에 담아주었다. `A` 구조체는 `수포자의 번호`와 `수포자의 총점`이 담겨있다. 따라서 `answers`의 `size`만큼 반복하며 정답과 쓴 답이 일치하면 해당 `total`을 증가시킨다.

그 다음 `total`을 기준으로 `내림차순` 정렬하였다.

`answer`에 최댓값(`aa[0].num`)을 담고, 높은 점수를 받은 사람이 여러명이면 또 담고 `num`을 오름차순 정렬하여 출력하였다.


## 마무리
완전탐색 문제를 많이 풀어봐야겠다.