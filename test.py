class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return s

        # s[0] 是字母
        if s[0].isalpha():
            # 分离出 s[0]，解码剩下的
            return s[0] + self.decodeString(s[1:])

        # s[0] 是数字，后面至少有一对括号
        i = s.find('[')  # 找左括号
        # 找右括号，注意对于 [...[...]...] 这种情况，第一个右括号并不是我们要找的，第二个才是
        balance = 1  # 左括号个数减去右括号个数
        for j in count(i + 1):  # 从 i+1 开始向右遍历，找与 s[i] 匹配的右括号
            if s[j] == '[':
                balance += 1
            elif s[j] == ']':
                balance -= 1
                if balance == 0:  # 左右括号个数相等，找到与 s[i] 匹配的右括号 s[j]
                    return self.decodeString(s[i + 1: j]) * int(s[:i]) + self.decodeString(s[j + 1:])
