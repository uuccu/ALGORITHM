# [Silver I] 팰린드롬 파티션 - 2705 

[문제 링크](https://www.acmicpc.net/problem/2705) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 재귀

### 문제 설명

<p>A partition of a positive integer N is a sequence of integers which sum to N, usually written with plus signs between the numbers of the partition. For example</p>

<p>15 = 1+2+3+4+5 = 1+2+1+7+1+2+1</p>

<p>A partition is palindromic if it reads the same forward and backward. The first partition in the example is not palindromic while the second is. If a partition containing m integers is palindromic, its left half is the first floor(m/2) integers and its right half is the last floor(m/2) integers (which must be the reverse of the left half. (floor(x) is the greatest integer less than or equal to x.)</p>

<p>A partition is recursively palindromic if it is palindromic and its left half is recursively palindromic or empty. Note that every integer has at least two recursively palindromic partitions one consisting of all ones and a second consisting of the integer itself. The second example above is also recursively palindromic.</p>

<p>For example, the recursively palindromic partitions of 7 are:</p>

<p>7, 1+5+1, 2+3+2, 1+1+3+1+1, 3+1+3, 1+1+1+1+1+1+1</p>

<p>Write a program which takes as input an integer N and outputs the number of recursively palindromic partitions of N.</p>

### 입력 

 <p>The first line of input contains a single integer N, (1 £ N £ 1000) which is the number of data sets that follow. Each data set consists of a single line of input containing a single positive integer for which the number of recursively palindromic partitions is to be found.</p>

### 출력 

 <p>For each data set, you should generate one line of output with the following values: The data set number as a decimal integer (start counting at one), a space and the number of recursively palindromic partitions of the input value.</p>

