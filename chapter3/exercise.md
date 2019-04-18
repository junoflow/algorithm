# chapter3 exercise

1. 한 번 분할할 때마다 n/2가 되므로 총 분할 횟수는 n/(2<sup>k</sup>)가 1이 될 때니까, k=log<sub>2</sub>n이다. 한 번 분할할 때마다 부분문제가 2개 생기므로, 전체 부분문제의 개수는 2<sup>k</sup>=2<sup>log<sub>2</sub>n</sup>=n

2. 한 번 분할할 때마다 n/2가 되므로 최대 분할 횟수 k=log<sub>2</sub>n이다. 부분문제의 수는 3<sup>log<sub>2</sub>n</sup>=n<sup>log<sub>2</sub>3</sup>개 이다.

3. 부분문제의 수는 a<sup>i</sup>이고, 이 때의 입력 크기는 n/(b<sup>i</sup>)이다.

4. 3을 바탕으로 생각해보면, 최대 분할 횟수 k=log<sub>b</sub>n이고, 이 때 부분문제의 수는 a<sup>log<sub>b</sub>n</sup>=n<sup>log<sub>b</sub>a</sup>개 이다.

5. 생략

6. iterative merge가 뭔지 모르겠당.

7. 우리 배운 partition 쓰면 될 듯.
굳이 적자면
```
Partition (A, left, right, p) {
  index i, j;
  key pitem;
  pitem = A[left] // pivot element를 가장 왼쪽 것으로.
  i = left; j = right+1;
  do {
    do i++;
    while (A[i] < pitem) // pitem보다 크면 멈춤
    do j--;
    while (A[j] > pitem) // pitem보다 작으면 멈춤
    if (i<j) exchange A[i] and A[j];
  } while (i<j)
  p = j;
  exchange A[left] and A[p]
}
```

8.
|0||1|2|3|4|5|6|7|8|9|10|11|
|---|---|---|---|---|---|---|---|---|---|---|---|
|8|3|11|9|12|2|6|15|18|10|7|4|
