# [Silver V] 카약 - 2890 

[문제 링크](https://www.acmicpc.net/problem/2890) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 정렬, 문자열

### 제출 일자

2024년 8월 10일 23:17:31

### 문제 설명

<p>Mirko and Slavko are sports commentators on a local kayaking competition. They have a live satellite feed of the entire track. Since there are too much teams for our dynamic duo to follow, they asked you to help them. They would like you to write a program that will display current standings teamby-team.</p>

<p>The satellite feed is encoded as a table of R rows C characters each. The first character in each row is the starting line, encoded by the character 'S'. The last character in each row is the finishing line, encoded by 'F'. There are exactly nine kayaks on the image. Each kayak is marked by his number, and each spans exactly three consecutive columns. Water is marked by '.'.</p>

<p>Teams are ranked by their distance to the finish line. Smaller is better. If two teams are at the same distance, they share their place.</p>

### 입력 

 <p>The first line of input contains two integers R and C (10 ≤ R, C ≤ 50), the number of rows and columns of the encoded satellite image.</p>

<p>Each of the following R lines contains exactly S characters '.', 'S', 'F' and 'digits 1' to '9'. Each row will contain at most one kayak.</p>

<p>Each image contains all 9 kayaks.</p>

### 출력 

 <p>Output nine lines, one for each kayak. The i<sup>th</sup> line should contain the current rank of the i<sup>th</sup> team.</p>

