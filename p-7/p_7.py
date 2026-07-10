class Solution:
    def reverse(self, x: int) -> int:
        str_x = list(str(x)[::-1])
        if str_x[-1] == "-":
            for i in range(len(str_x) - 1, 0, -1):
                str_x[i] = str_x[i - 1]

            str_x[0] = "-"

        return_x = int("".join(str_x))

        if return_x < -1 * (2 ** 31) or return_x > 2 ** 31 - 1:
            return 0
        else:
            return return_x 
