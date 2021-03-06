/*
https://leetcode.com/problems/fraction-to-recurring-decimal/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
*/


class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
    if(numerator == 0)
		return "0";
	string res;
	if((numerator >= 0 && denominator < 0)||(numerator < 0 && denominator >= 0))
		res = "-";
	numerator = abs(numerator);
	denominator = abs(denominator);
	long long dividend = numerator / denominator;
	long long rem = numerator % denominator;
	res += to_string(dividend);
	if(rem == 0)
		return res;
	res.push_back('.');
	unordered_map<int,int> map;
	while(rem > 0)
	{
		numerator = rem * 10;
		if(map.find(numerator) != map.end())
		{
			int pos = map[numerator];
			return res.substr(0, pos) + "(" + res.substr(pos) + ")";
		}
		map[numerator] = res.length();
		dividend = numerator / denominator;
		rem = numerator % denominator;
		res.push_back(dividend + '0');
	}
	return res;
    }
};