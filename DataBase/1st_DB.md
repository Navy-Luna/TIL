# 1st_week_데이타베이스: Why Databases?

## 1. Why use a Database?
### ★ Prevalence of DataBase
- 성공적인 사이트 운영뒤에는 강력한 데이터베이스가 필요함 : 가지고있는 정보량이 매우 많기때문에 이를 통합적으로 관리하고 저장할 데이터베이스가 필요한것임
- 예) Amazon, E-consumer, Google's search engine 등에서 다수 활용

### ★ Data Mangagement Example
내가 만약 DVD 렌탈 숍을 차리고할때 우리는 언제 고객들이 그것을 빌려갔는지, DVD 대여 만기날짜에 가까워지고 있는 것은 어떤건지, Blue-ray의 재고는 얼마나 남았는지와 같은 정보들을 관리하고 저장할만한 시스템이 필요함. 그 방법이란 뭘까?

- "File-based" System
  + File 기반 정보 관리가 하나의 대안이 될 수 있음.
  + 파일에다가 dvd 이름은 뭐고 고객 정보는 뭔지 같은 정보들을 저장해두면 됨(메모장 같은 곳에 일일이 정보들을 타이핑해서 넣어둔다고 생각하면됨)
  + Text editors are easy to use(텍스터 에디터는 사용하기 쉬움)
  + Simple to insert/delete a record(레코드-정보를 담은 행-을 쉽게 삽입/삭제 가능)
  + 하지만 이런 파일기반 시스템에는 한계가 존재!!

- File 기반 데이터 관리 과정에서 마주치는 여러 문제점들(Complications) & 필요한 technique  
  1. Queries(질의)
