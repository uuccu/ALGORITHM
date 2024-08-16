from itertools import permutations

def apply_permutation(block, perm):
    return ''.join(block[p-1] for p in perm)

def compress_size(s):
    count = 1
    size = 0
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            count += 1
        else:
            size += 1
            count = 1
    return size + 1

def min_compressed_size(s, k):
    n = len(s)
    min_size = float('inf')
    
    for perm in permutations(range(1, k+1)):
        permuted = ''
        for i in range(0, n, k):
            permuted += apply_permutation(s[i:i+k], perm)
        min_size = min(min_size, compress_size(permuted))
    
    return min_size

def solve_cases(n):
    for case in range(1, n+1):
        k = int(input())
        s = input().strip()
        result = min_compressed_size(s, k)
        print(f"Case #{case}: {result}")

# Main execution
if __name__ == "__main__":
    N = int(input())
    solve_cases(N)