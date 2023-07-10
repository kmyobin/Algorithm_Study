## Info
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/42578" rel="nofollow">의상 </a>

## ❗풀이
- multimap과 set을 사용

카테고리는 set에 담고 multiset에 카테고리와 옷을 담는다.
set의 개수가 1개면 그냥 옷을 개수를 출력하고 그 이상이라면 
카테고리별 옷의 개수에 + 1을 하고 곱해준다. 그리고 그 값에서 1을 빼준다.


## 마무리
multimap을 처음 사용해 봤는데 iterator로 접근하는 방식을 더 공부해봐야겠다. 
중복을 포함하거나 포함하지 않는 경우 모두를 사용할 수 있으면 문제를 더 쉽게 풀수있다.