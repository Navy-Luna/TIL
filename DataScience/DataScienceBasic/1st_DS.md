# 1st_데이터과학기초: Introduction to Data Science(데이터과학 소개)   
- 강의계획서: [3학년_1학기_데이터과학기초](https://knuin.knu.ac.kr/websquare/popup.html?w2xPath=/views/cmmnn/popup/windowpopup.xml&popupID=publicLectPlnInputDtlPop&w2xHome=/stddm/lsspr/public/&w2xDocumentRoot=)
- 상세계획서: [DS_상세계획서](https://docs.google.com/spreadsheets/d/1kP4eLNPn0fCpxtwpP8HuYIdmEZ30XqL6jUhS21zn2Vk/edit?usp=sharing)

## 1. What is Data Science?(무엇이 데이터 사이언스인가?)
1. 데이터과학은 데이터를 연구하는 학문임. 데이터로부터 extracting(뽑아내고), analyzing(분석하고), visualizing(시각화하고), managing(관리하고), and storing(저장한다)과정을 거쳐 insight를 만들어냄 -> 우리가 한학기동안 살펴볼 내용   
2. 이런 데이터 처리과정을 기반으로한 insight로 "결정"을 내리게 됨(data-driven dicision). 이런 데이터들은 unstructured data와 structured data로 나뉜다.   
3. 다양한 분야의 지식(multidisciplinary field)을 필요로한다. Data Science는 computer science/IT, Domain/Business knowledge, and math and statistics의 공통집합꼴. (참고로 domain knowledge란, 특정한 전문화된 분야나 학문의 지식)
4. 결국, 계산(computation)하여 데이터로부터 세계에 대해 이해해나가는 학문임(탐구하고 추론하고 예측한다)

- Exploration(탐구)
  + Identifying patterns in data (데이터 항목간의 관계/패턴 파악)
  + Uses visualization (값들의 분포를 눈에 보이기/이해하기 쉽게 표시)
- Inference(추론)
  + Using data to draw reliable conclusions about the world (데이터로부터 신뢰성있는 결론을 이끌어냄)
  + Uses statistics (수학-통계 사용)
- Prediction(예측)
  + Making informed guesses about unobserved data (아직 관찰되지 않은 데이터 추이을 추측 Ex.미래에도 상승할것이다.)
  + Uses Machine learning (예측을 도와주는 IT기술 활용-머신러닝) -> 채용공고를 보면 ML뿐만 아니라 DL 활용능력도 함께 요구하는 경우가 많아보임

## 2. Why Data Science?(왜 데이터 사이언스를 고르나?)
### ☆ Advantages
1. 수요가 증가할 것임: 데이터를 기반으로 미래를 예측하는 영역이 점점 넓어지고 있기 때문 - 넷상의 정보의 축척량이 늘어나고 있기 때문
2. Data Science는 요구되는 skill-set이 많은 편이라 그만큼 전공자가 적음. 수요에 비해 공급이 적기때문에 유망.
3. 월금이 쎄다.
4. 회사에서의 의사결정에 큰 영향을 끼치기 때문에 그만큼 대우가 좋다.
5. 매우 versatile(변하기 쉬운) 영역이기 때문에 various field에서 일할 기회가 주어진다.

### ☆ Disadvantages
1. 매우 애매모호한 영역임: 매우 general하게 사용하는 용어라 그 경계가 애매모호함, data scientist의 역할은 그 회사에서 specializing한 영역으로 정의되는게 대부분임(이커머스, 헬스케어 등)
2. DS를 마스터한다는것은 불가능에 가까움. 데이터 사이언스라는 것 자체가 모호해서 그것에 들어가는 framework, visualization tool 등을 모두 이해하기란 불가능한것임
3. 아무리 통계학 지식과 computer science 지식을 가지고 있다고 하더라도 background knowledge에 해당하는 domain knowledge를 필수로 알아야함. 양이 많기 때문에 쉽지는 않다..
4. 임의의 데이터로 인해 예상치못한 결과가 도출될 수 있다.
5. 데이터를 사용하는 직업이기 때문에 data privacy와 같은 ethical한 문제와 충돌할 가능성이 높다.

## 3. Why is DK(Domain Knowledge) for a DS(Data Science)?(기반 지식이 데이터 사이언스에 중요한 이유?)
1. Source Problem, the business is trying to resolve and/or capitalize on.
2. The set of specialized information or expertise held by the business.
3. The exact know-how, for domain specific data collection mechanisms.

## 4. Data Science Process(데이터 사이언스가 일을 처리하는 과정)
1. Problem Framing: 문제를 분명하고 정확하게 규정함
2. Data Acqustion: 필요한 데이터를 취득함
3. Data Preparation: EDA([설명1](https://jalynne-kim.medium.com/%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B6%84%EC%84%9D-%EA%B8%B0%EC%B4%88-eda%EC%9D%98-%EA%B0%9C%EB%85%90%EA%B3%BC-%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B6%84%EC%84%9D-%EC%9E%98-%ED%95%98%EB%8A%94-%EB%B2%95-a3cac2cc5ebc)/[설명2](https://eda-ai-lab.tistory.com/13))를 기반으로한 데이터 처리와 변형
4. Model Planning: Data Set을 위한 Training Model을 결정함(회귀,분류 이용)
5. Model Building: Training Data로 모델을 만들어내고 Test data로 테스트를 진행
6. Visualization Communication: 데이터의 숨겨진 패턴을 찾아내고 actionable insight를 위한 contrasting visual을 준비함(대조군 준비? 같음)
7. Deployment/Maintenance: 모델을 배포하고 새로운 데이터에 기반하여 모델을 수정하고 보수함.

![DataScience_team_graphics_03](https://user-images.githubusercontent.com/97028605/189873766-b42e1df0-7317-4404-909a-a1c82f8b1ab1.jpg)

## 5. Data related Job
1. Data Scientist(데이터 사이언티스트): 방대한 데이터와 다양한 툴, 기술, 방법론, 알고리즘을 사용하여 강력한 비즈니스 비전을 제시하는 전문가(ML을 이용해 미래 예측에 중점)
2. Data Engineer(데이터 엔지니어): 방대한 데이터를 큰 규모의 처리 시스템이나 데이터베이스와 같은 아키텍쳐를 만들고, 테스트하고, 개발함으로서 데이터를 관리하는 직군
3. Data Analyst(데이터 분석가): 데이터들을 뽑아내어 데이터간의 관계, 트랜드, 패턴을 파악해냄. 데이터를 분석하여 visualization 하며 분석 내용을 토대로 비즈니스의 결정에 중요한 역할을 수행함. (과거와 현재에 더 중점을 맞춰 데이터를 분석하며 개발자와 경영자 사이의 중계역할을 한다고 보면 됨)

이외에는 Statistician(통계전문가), Data Administrator(데이터 관리자), Business Analyst(비즈니스 분석가)가 있음.. 더 자세한 내용은 [데이터분석가vs데이터엔지니어vs데이터사이언티스트](https://socrates-dissatisfied.tistory.com/entry/%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B6%84%EC%84%9D%EA%B0%80-vs-%EB%8D%B0%EC%9D%B4%ED%84%B0%EC%97%94%EC%A7%80%EB%8B%88%EC%96%B4-vs-%EB%8D%B0%EC%9D%B4%ED%84%B0%EA%B3%BC%ED%95%99%EC%9E%90%EC%82%AC%EC%9D%B4%EC%96%B8%ED%8B%B0%EC%8A%A4%ED%8A%B8-%EC%B0%A8%EC%9D%B4%EB%8A%94) 참고   

### 6. Data Scientist에 바라는 역량(T자형 그래프)
<img width="500" height="350" alt="스크린샷 2022-09-13 오후 7 55 30" src="https://user-images.githubusercontent.com/97028605/189883692-76ea5988-2e53-4021-a261-5f059a7ed1ca.png"> <img width="500" height="350" alt="스크린샷 2022-09-13 오후 7 56 32" src="https://user-images.githubusercontent.com/97028605/189884058-940e79fd-a84a-4fb2-989d-2184c51c56ae.png">

### 7. Difference of Between DS and BI(Business Intelligent) - BI는 Data Analyst와 하는일이 비슷하다고 봐도 될듯
<img width="845" alt="스크린샷 2022-09-13 오후 8 03 58" src="https://user-images.githubusercontent.com/97028605/189885345-cf4dc77f-05de-40e0-907d-6573407e58ae.png">


