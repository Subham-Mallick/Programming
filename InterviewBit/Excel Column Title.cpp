string Solution::convertToTitle(int n) {
string result;
while (n > 0) {
    int mod = n % 26;
    char c;
    if (mod == 0) { // n = 26 corresponds to 'Z'
        c = 'Z';
    } else {
        c = (mod - 1) + 'A'; //n = 1 corresponds to 'A', n = 2 corresponds to 'B', etc
    }
    result = c + result;
    n = (n - 1) / 26; // just like n / 10 gets rid of the last digit in the base 10 representation of a number, so too do we get rid
	                  //of the last letter in the excel representation of a number by dividing by 26.
			          //The -1 is there because the digit in the excel representation of a number starts at 'A' == 1 rather than 0.
}
return result;
}
