from typing import List


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Returns the index of the first occurrence of `needle` in `haystack`, or -1 if `needle` is not part of `haystack`.

        Args:
            haystack (str): The string to search within.
            needle (str): The substring to search for.

        Returns:
            int: The index of the first occurrence of `needle` in `haystack`, or -1 if not found.
        """
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i
        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.strStr("sadbutsad", "sad"))
