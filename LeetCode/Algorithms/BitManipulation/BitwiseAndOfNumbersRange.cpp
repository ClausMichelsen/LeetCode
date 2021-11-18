// Problem: https://leetcode.com/problems/bitwise-and-of-numbers-range/
int BitwiseAndOfNumbersRange_Recursive(int left, int right)
{
	return left != right ? BitwiseAndOfNumbersRange_Recursive(left >> 1, right >> 1) << 1 : right;
}



int BitwiseAndOfNumbersRange_Iterative(int left, int right)
{
	int shifts{};
	while (left != right)
	{
		left >>= 1;
		right >>= 1;
		++shifts;
	}

	return left << shifts;
}
