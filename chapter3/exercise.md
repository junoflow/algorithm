# chapter3 exercise

1. 한 번 분할할 때마다 n/2가 되므로 총 분할 횟수는 n/(2<sup>k</sup>)가 1이 될 때니까, k=log<sub>2</sub>n이다. 한 번 분할할 때마다 부분문제가 2개 생기므로, 전체 부분문제의 개수는 2<sup>k</sup>=2<sup>log<sub>2</sub>n</sup>=n

2. 한 번 분할할 때마다 n/2가 되므로 최대 분할 횟수 k=log<sub>2</sub>이다. 부분문제의 수는 3<sup>log<sub>2</sub>n</sup>==n<sup>log<sub>2</sub>3</sup>개 이다.

3. 1, 2번 문제를 바탕으로 계산해보면, 부분문제의 수는 a<sup>i</sup>이고, 이 때의 입력 크기는 n/(b<sup>i</sub>)이다.
