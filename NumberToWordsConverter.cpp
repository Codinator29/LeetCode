#include <iostream>
#include <unordered_map>
using namespace std; // consider removing this line in serious projects 


class NumberToWordsConvertor
{
    public:
    string numberToWords(int number)
    {
        if(number == 0)
        {
            return "Zero";
        }
        
        if(number < 0)
        {
            return "";
        }
        
        string result;
        
        for(int divs = 1e9; divs > 0; divs /= 1e3)
        {
            int quotient = number / divs;
            if(quotient == 0)
            {
                continue;
            }
            result += Process(quotient);
            result += LargerNums.at(divs);
            number %= divs;
        }
        
        return result.substr(1);
    }
    
    string Process(int number)
    {
        string res = "";
        
        if(number >= 100)
        {
            res += " " + Digits.at(number / 100) + " Hundred";
            number %= 100;
        }
        
        if(number >= 20)
        {
            res += " " + Tens.at(number / 10 * 10);
            number %= 10;
        }
        
        if(number >= 10)
        {
            res += " " + TensToNineteen.at(number);
            number = 0;
        }
        
        if(number > 0)
        {
            res += " " + Digits.at(number);
        }
        
        return res;
    }
    
    static const unordered_map<int, string> Digits;
    static const unordered_map<int, string> TensToNineteen;
    static const unordered_map<int, string> Tens;
    static const unordered_map<int, string> LargerNums;
};

const unordered_map<int, string> NumberToWordsConvertor:: Digits = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6 ,"Six"}, {7, "Seven"}, {8,"Eight"}, {9, "Nine"}};

const unordered_map<int, string> NumberToWordsConvertor:: TensToNineteen = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};

const unordered_map<int, string> NumberToWordsConvertor:: Tens = {{20 ,"Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};

const unordered_map<int, string> NumberToWordsConvertor:: LargerNums = {{1, ""}, {1e3, " Thousand"}, {1e6, " Million"}, {1e9, " Billion"}};

int main() { 
   NumberToWordsConvertor numberToWordsConvertor;
   cout << numberToWordsConvertor.numberToWords(1234567891);
   return 0; 
}