from typing import List


class Solution:
    def triangleType(self, nums: List[int]) -> str:
        """
        Determine the type of triangle that the three side lengths form.

        Args:
            nums (List[int]): A list of three integers representing side lengths.

        Returns:
            str: One of "none", "equilateral", "isosceles", or "scalene".
        """
        nums.sort()
        if (nums[0] + nums[1] <= nums[2]):
            return "none"
        if (nums[0] == nums[1] or nums[1] == nums[2]):
            if (nums[0] == nums[2]):
                return "equilateral"
            else:
                return "isosceles"
        return "scalene"


if __name__ == "__main__":
    sol = Solution()
    print(sol.triangleType([2, 3, 1]))
