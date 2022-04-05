 ## 1.5 Performace Analysis(성능 분석)
 * Performace Evaluation(성능평가)
    + Performace Analysis(성능분석 - time과 space로 추정하며 machine independent하다.)
      - Space Complexity(공간복잡도) : 프로그램이 running 하는데 필요한 메모리 요구량
      - Time Complexity(시간복잡도) : 프로그램이 running 하는데 필요한 계산 시간 양
    + Performace measurment(성능측정 - machine dependent하다.)
    
 ### 1.5.1 Space Complexity
 > S(p) = c + Sp(I)

 - S(p) : 프로그램 P의 전체 space 요구량
 - c : constant하게(고정되게) 요구되는 space 요구량
 - Sp(I) : 인스턴스 I(예를 들어, 배열)를 처리하며 변화가능한 space 요구량 ~ 인스턴트 I의 I/O와 관련된 number, size, value의 영향을 받는다.   

Sp(I)에서 길이가 n인 배열을 처리할 때, n은 instance characteristic이며 오직 n에만 영향을 받는다면 Sp(n)으로 적을 수도 있다. Sp가 space complexity를 analysis하는데 가장 중요하게 봐야할 부분!

```c
  // 실행할 때마다 다른 크기의 메모리 용량이 필요한 것이 아니다. 따라서 Sabc(I)=0
  float abc(float a, float b, float c)
  {
     return a+b+b*c+(a+b-c)/(a+b) + 4.00;
  }
```

```c
  // 전달되는 n에 따라 사용하는 용량은 다르겠지만 실행마다 바뀐다는 느낌은 아님! -> 추가 용량 사용이 없음.. Ssum(I) = 0
  float sum(float list[], int n)
  {
     float tempsum = 0;
     int i;
     for(int i=0; i<n; i++)
       tempsum += list[i];
     return tempsum
  }
```

```c
  /* 아래와 같이 함수가 recursive하게 불려질 때, 컴파일러는 각 recursive call마다 스택 공간에 저장을 해야함! 
     -> 추가 용량 사용이 n에 따라 변화한다. Srsum(I) > 0 */
  float rsum(float list[], int n)
  {
     if (n) return rsum(list,n-1) + list[n-1];
     return 0;
  }
```
 
### 1.5.2 Time Complexity
와 뭐야
