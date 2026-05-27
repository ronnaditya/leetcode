class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a_flipped = a[::-1]
        b_flipped = b[::-1]
        c = []

        longer = len(a) if len(a) > len(b) else len(b)
        shorter = len(a) if len(a) < len(b) else len(b)
        
        carry = 0
        for i in range(shorter):
            if a_flipped[i] == "0" and b_flipped[i] == "0":
                if carry:
                    c.append("1")
                    carry = 0
                else:
                    c.append("0")
            elif (a_flipped[i] == "0" and b_flipped[i] == "1") or (a_flipped[i] == "1" and b_flipped[i] == "0"):
                if carry:
                    c.append("0")
                    carry = 1
                else:
                    c.append("1")
            elif a_flipped[i] == "1" and b_flipped[i] == "1":
                if carry:
                    c.append("1")
                    carry = 1
                else:
                    c.append("0")
                    carry = 1
        
        switch = 0 if len(a) > len(b) else 1
        strings = [a_flipped, b_flipped]
        for i in range(shorter, longer):
            if strings[switch][i] == "0":
                if carry:
                    c.append("1")
                    carry = 0
                else:
                    c.append("0")
            else:
                if carry:
                    c.append("0")
                    carry = 1
                else:
                    c.append("1")
        if carry:
            c.append("1")
        return "".join(c[::-1])
