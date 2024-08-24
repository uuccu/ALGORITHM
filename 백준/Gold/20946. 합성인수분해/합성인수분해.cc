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

vector<int> dp[1000001];
vector<int> primes;

vector<int> k_eratosthenes(int k) {
    vector<bool> is_prime(k + 1, true);
    vector<int> ret;

    for (int i = 2; i < k; i++) {
        if (is_prime[i]) {
            ret.push_back(i);
            for (int j = i; j < k; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return ret;
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
    ll n;
    cin >> n;

    list<ll> prime_lists;

    ll tmp = n;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            prime_lists.push_back(i);
        }
    }
    if (n != 1)prime_lists.push_back(n);

    if (prime_lists.size() <= 1) {
        cout << -1;
        return;
    }

    vector<ll> answer;

    while (!prime_lists.empty()) {
        auto x = prime_lists.front();
        prime_lists.pop_front();
        if (prime_lists.size() >= 1) {
            auto tmp = prime_lists.front();
            prime_lists.pop_front();
            x *= tmp;
            answer.push_back(x);
        } else {
            answer[answer.size() - 1] *= x;
        }

    }
    sort(answer.begin(), answer.end());

    for (auto x: answer)cout << x << " ";

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
