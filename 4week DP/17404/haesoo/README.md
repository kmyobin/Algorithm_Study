## Info
<a href="https://www.acmicpc.net/problem/17404" rel="nofollow">17404 RGB 거리 2 </a>

## ❗풀이
- 1번 집에 칠할 색깔을 고정하고, 2 ~ N - 1번 째 집까지 DP를 적용하여 각 값을 구한다. 마지막 N번 째 집에서 1번 집에 칠한 색을 제외한 두 가지 색깔에서 최소 금액을 구하여 지정한다.
## 마무리
 기존 RGB 문제를 먼저 찾아 보았는데, 1번 집 색과 N번 집 색의 중복 허용이 가능했던 기존 문제와 달리, 원 모양처럼 처음과 끝이 겹치면 안되는 유형이었다. 