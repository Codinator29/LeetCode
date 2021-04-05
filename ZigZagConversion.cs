/*

https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

*/

public class Solution {
    public string Convert(string s, int numRows) {
    if (numRows == 1) 
        return s;
	int offset = numRows * 2 - 2;
	string result = "";
	int length = s.Length;
	int index = 0;
	int row = 1;
	int first = 0, second = 0;
	while (row <= numRows) {
		first = offset - (row - 1) * 2;
		second = offset - first;
		while (index < length) {
			result += s[index];
			if (row == 1 || row == numRows) {
				index += offset;
			} else {
				index = index + first;
				if (index < length) {
					result += s[index];
					index += second;
				}
			}
		}
		row++;
		index = row - 1;
	}
	return result;
    }
}