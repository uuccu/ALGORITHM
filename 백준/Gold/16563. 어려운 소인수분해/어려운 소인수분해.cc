#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <list>
#include <cmath>

typedef long long ll;
#define endl "\n"
using namespace std;


map<int, vector<int>> m;

void find_divisors(int num) {

}


//
//}
//
//void solution(int testcase) {
//    int n;
//    vector<int> v(n);
//    vector<int> ans(n, 0);
//
//    cin >> n;
//    for (auto &x: v)cin >> x;
//
//    for (int i = 0; i < n; i++) {
//
//
//    }
//
//
//}


vector<int> dp[5000001];
vector<int> primes;

vector<int> k_eratosthenes(int k) {
    vector<bool> is_prime(k + 1, true);
    vector<int> primes;

    for (int i = 2; i < k; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i; j < k; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

vector<int> get_prime_factor(int input) {
    if (!dp[input].empty()) return dp[input];
    vector<int> answer;
    if (input == 1)
        return answer;

    int idx = 0;
    while (primes[idx] <= input) {
        if (input % primes[idx] == 0) {
            answer = get_prime_factor(input / primes[idx]);
            answer.push_back(primes[idx]);
            break;
        }
        idx++;
    }
    return dp[input] = answer;
}


void solution(int t) {
    int n;
    cin >> n;
    vector<int> input(n);
    for (auto &x: input)cin >> x;
    primes = k_eratosthenes(5000001);

    for (int i = 0; i < primes.size(); i++) {
        dp[primes[i]].push_back(primes[i]);
    }

    for (int i = 0; i < n; i++) {
        get_prime_factor(input[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(dp[input[i]].begin(), dp[input[i]].end());
        for (auto x: dp[input[i]])cout << x << " ";
        cout << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    for (int i = 0; i < testcase; i++)
//        solution(i);
    solution(0);
}
