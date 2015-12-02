# Markdown 문서 작성 방법
```
Github에서 README(.md) 작성하기(Markdown 문법)
Github에 Repository를 만들고 root에 README(or Readme.md, Readme.markdown 중 한개로 쓰면됩니다.)를 만들어 넣으면 Github에서 
자동으로 Code 탭에서 보여줍니다.

하지만 아무렇게나 작성해도 되지만 “GitHub Flavored Markdown” (GFM)이라는 문법에 맞게 작성하면 더 보기 편하게 보여줍니다.

GFM이란?
GFM은 표준 Markdown(SM)에 조금더 편하게 변경한 github 버젼입니다. 그리고 Markdown은 Plain text로 작성된 파일을 HTML로 
변경해서 보여주기 위한 문법입니다.

GFM 문법
<줄바꿈>

SM이랑 가장 큰 차이점으로 문장의 줄바꿈을 그대로 반영합니다.(즉, “enter”로 줄바꿈 구분함)

<헤더>

H1 = 또는 #

H2 – 또는 ##

H3 ### , H4 #### , H5 ##### , H6 ######

(=), (-) 은 연속으로 몇개가 오든 상관없이 동작합니다.

<Blockquotes>

> , >> 등

<리스트>

+ 가 -> <li>가</li>

* 가 -> <li>가</li>

– 가 -> <li>가</li>

(+), (*), (-)는 모두 똑같이 동작하며 (기호 + “공백” + 내용) 입니다.

<숫자 리스트>

1. 가

2. 나

숫자 + “.” + “공백” + 내용 (“.” 뒤에 공백이 와야 리스트 입니다.)

<코드>

무조건 빈줄을 하나 넣어줘 준 다음 공백 4개(”    “) 로 시작하면 됩니다.

또는 “` 로 시작해서 “` 으로 끝내면 됩니다.

코드 안에서는 자동으로 escap 처리를 해줍니다.(<, > 등등)

리스트안에서 코드는 “` 로 해줘야 합니다.

<Link>

[링크명](url)
```

더 자세한 내용은 밑에 참조 자료 참고 

마크다운 문법 교육 자료 : http://sergeswin.com/1013

```
'작성자 : https://github.com/GangHoyong'
```
