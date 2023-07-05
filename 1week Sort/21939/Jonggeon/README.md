## Info
<a href="https://www.acmicpc.net/problem/21939" rel="nofollow">21939 문제 추천 시스템 Version 1 </a>

## ❗풀이
- priority_queue를 사용한 풀이
recommend, add, solved 의 명령어를 받아 처리하는 문제다.
recommend와 add는 간단하게 구현 가능하지만 solved를 구현하는게 이 문제의 포인트인 것 같다.

오름차순과 내림차순의 priority를 사용해 recommend와 add를 구현했다.
solveds는 새로운 Int배열을 만들어 solved한 문제는 값을 0으로 바꾸어 처리했다.
즉 queue에서 가장 큰 값 'a'가 Int배열에서 0이라면 다음 값을 출력하고 Int배열[문제번호]와 같은 값이라면
그 값을 출력한다.

## 마무리
새로운 풀이 방법보다는 이미 알고있는 방법에 추가하여 푸는게 현실적으로 더 빠른것 같다.