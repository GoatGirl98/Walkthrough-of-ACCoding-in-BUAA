def lengthofLongestSubstring(s: str) -> int:
    maxlen = 0
    memo = dict()
    begin, end = 0, 0
    n = len(s)
    while end < n:
        last = memo.get(s[end])
        memo[s[end]] = end
        if last is not None:
            maxlen = max(maxlen, end - begin)
            begin = max(begin, last + 1)
        end += 1
    maxlen = max(maxlen, end - begin)
    return maxlen

if __name__ == '__main__':
    s = input()
    print(lengthofLongestSubstring(eval(s)))