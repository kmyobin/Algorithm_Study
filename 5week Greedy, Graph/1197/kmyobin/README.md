## Info
<a href="https://www.acmicpc.net/problem/1197" rel="nofollow">1197 �ּ� ���д� Ʈ��</a>


## Ǯ��
`�ּ� ���д� Ʈ��(MST)`�����̴�. `�ּ� ���д� Ʈ��`�� `�׷��� ���� ��� ������ ��ġ�� cycle�� �������� �����鼭 ����ġ�� ���� �ּ��� Ʈ��`�̴�. 

��ǥ�����δ� `Prim` �˰������ `Kruskal` �˰������� �ִµ�, �б����� �˰����� ���踦 �����ߴ� ��� `Prim`�� ���� ����� �� ���� �����߱� ������ `Prim`�� �����Ͽ���.

�� �� �湮�ߴ� ������ �ٽ� �湮�ϸ� �ȵǱ� ������ `bool visited[10001]`�� �����Ͽ� �������־���.

`Edge` ����ü�� ���� ���� ���ϴ���(`to`), ����ġ�� ������(`weight`)�� ��Ҵ�. 

`�켱���� ť`�� �����Ͽ��µ�, �̴� �⺻���� ��������(`�ִ���`)���� �����ϱ� ������ ���� ����ġ�� �켱�� �ϴ� �� ���������� `�ּ���`���� ������ �ʿ䰡 �־���. ���� `������ �����ε�`�� �̿��Ͽ� ������������ �����Ͽ���. ���� `pq`�� `pop`�� ������ ���� ���� ����ġ�� ���� `Edge`�� ���� �� �ִ� ���̴�.

## ������
�۳⿡ ����� `MST`�� ���� �ݰ������� ���� �˰������� ¥���� �������. ���α׿� �ִ� �ڵ���� �����Ͽ� �ۼ��Ͽ���.