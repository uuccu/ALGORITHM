#include<bits/stdc++.h>
struct Trie {
    unordered_map<int, Trie*> ch; // 각 숫자를 키로 갖는 자식 노드맵
    int cnt = 0;
    int insert(vector<int>& nums, int i, int k, int p) {
        if (i == nums.size() || k - (nums[i] % p == 0) < 0)// base case
            return 0;
        if (ch[nums[i]] == nullptr)// 없으면 생성
            ch[nums[i]] = new Trie();
        return (++ch[nums[i]]->cnt == 1) + // 새로 생성된 경우에면 + 1 왜냐면 그게 새로운 부분집합이므로.
            ch[nums[i]]->insert(nums, i + 1, k - (nums[i] % p == 0), p);
            // i을 통해 순차적으로 탐색, k는 나누어떨어지는지를 확인하고 -연산, 
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) { // k는 p로 나누어 떨어지는 원소의 최대 개수를 말함. 
        int res = 0;
        Trie t;// 문자열을 넣지 않고 경우의수가 나오게 함.
        for (int i = 0; i < nums.size(); i++)// 배열순회하면서 insert
            res += t.insert(nums, i, k, p);
        return res;    
    }
};