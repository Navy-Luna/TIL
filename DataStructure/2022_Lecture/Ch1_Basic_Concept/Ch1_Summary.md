# Ch1. Basic Concept

## 1.1 Overview: System Life Cycle
### Software development process(소프트웨어 개발 과정)

1. Requirement specification(요구사항 명세화) : 프로젝트의 목적을 정하고 명세화하여 명세서를 작성하는 단계
2. Problem Analysis(문제 분석) : 커다란 문제를 세부적으로 나누는 단계
3. System Design(시스템 디자인) : 프로그램에 필요한 Data Object를 정하고 Object에 사용할 Operation을 결정 - ADT(Abstract Data Type)을 정하고 Algorithm 명세화를 한다.(프로그램 언어와 무관하게 independent하게 진행된다.)
4. Coding&Refinement(코딩&개선) : Data Object를 표현할 것을 결정하고 실제로 알고리즘을 작성하는 단계
5. Verification(확인) : Correctness proofs/Testing/Error removal

## 1.2 Pointers and Dynamic Memory Allocation(포인터와 동적 메모리 할당)
- Pointer
  + & : the address operator(주소 연산자) - 변수에 붙이면 해당 정보가 저장된 메모리 주소를 확인 가능
  + \* : the dereferencing(or indirection) operator(역참조 주소 연산자) - 주소에 담겨있는 내용물을 확인 가능

[Variable And Pointer] 파일 참고

## 1.3 Algorithm Specification(알고리즘 상술)
1. Definitions of Algorithmns(알고리즘의 정의)
  알고리즘은 어떤 특정 목적을 달성하기 위한 유한한 명령어의 집합, 일종의 문제해결을 위한 메뉴얼이나 절차, 문제풀이법이라고 보면 된다. 알고리즘에는 따라야할 5가지 조건이 있음
  - input(>=0) : 0개 이상의 input이 들어가야함
  - output(>0) : 1개 이상의 output(결과물)이 나와야한다. - input과는 구별됨
  - definiteness(명확성) : 수행 과정은 명확하고 모호하지 않은 명령어로 정의되어있어야한다.
  - finiteness(유한성) : 유한 개의 명령어가 유한시간 내에 수행되어야한다. 답도 없이 계속 이어지는건 안된다.. Ex) While(1){printf(".")}
  - effectiveness(유효성) : 모든 과정은 실현 가능(검증이 가능)해야만 한다 = 알고리즘의 모든 연산들이 사람이 종이와 연필을 이용해서 유한한 시간안에 정확하게 수행될 수 있을 정도로 단순하여야 한다.
  
