#include "LongArithmetic.hpp"

LongNumber::LongNumber(std::string s){
    int position = 0;
    if (s[0] == '-'){
        sign = -1;
        position++;
    }
    else if(s[0] == '+'){
        sign = 1;
        position++;
    }
    else{
        sign = 1;
    }

    exponent = s.length() - position;
    int len = s.length();
    while(position < len){
        if(s[position] == '.'){
            if (s[0] == '-' || s[0] == '+'){
                exponent = position - 1;
            }
            else{
                exponent = position;
            }
        }
        else{
            Number.push_back(s[position] - '0');
        }
        position++;
    }
    remove_zeroes();
}

LongNumber::LongNumber(const LongNumber& x){
    sign = x.sign;
    exponent = x.exponent;
    int x_size = x.Number.size();
    Number = std::vector(x_size, 0);
    for(int i = 0; i < x_size; i++){
        Number[i] = x.Number[i];
    }
}

LongNumber::LongNumber(){
    sign = 1;
    exponent = 1;
    Number.push_back(0);
}

LongNumber LongNumber::remove_zeroes(){
    while(Number.size() > 1 && Number[0] == 0){
        Number.erase(Number.begin());
        exponent--;
    }
    while(Number.size() > 1 && Number.back() == 0){
        Number.pop_back();
    }
    if (Number.size() == 1 && Number[0] == 0){
        exponent = 1;
        sign = 1;
    }
    return *this;
}

LongNumber LongNumber::inverse_number(){
    LongNumber divisible("1");
    LongNumber divider(*this);
    divider.sign = 1;
    LongNumber ans;
    ans.sign = sign;
    ans.exponent = 1;
    ans.Number = std::vector<int>();
    int divider_size = divider.Number.size();
    while (divider_size > divider.exponent) {
		divider.exponent++;
		ans.exponent++;
	}
	while (divisible < divider){
		divisible.exponent++;
        ans.exponent--;
    }
    int num = 0;
	do{
		num = 0;
		while (divisible >= divider) {
			num++;
			divisible = divisible - divider;
		}
		divisible.exponent++;
		divisible.remove_zeroes();
		ans.Number.push_back(num);
    } while ((!((divisible.Number.size() == 1) && (divisible.Number[0] == 0))) && (int(ans.Number.size() - ans.exponent) < inverse_limit));
	return ans;
}

LongNumber LongNumber::rounding(int k){
    int len = Number.size() - exponent;
    while(len < k){
        Number.push_back(0);
        len++;
    }
    while (len > k){
        Number.pop_back();
        len--;
    }
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
	if (this == &x){
		return *this;
    }
	sign = x.sign;
	exponent = x.exponent;
    int x_size = x.Number.size();
	Number = std::vector<int>(x_size, 0);
	for (int i = 0; i < x_size; i++){
		Number[i] = x.Number[i];
    }
	return *this;
}

LongNumber LongNumber::operator- () const{
    LongNumber ans(*this);
    ans.sign *= -1;
    return ans;
}

bool LongNumber::operator> (const LongNumber& x) const{
    if(sign != x.sign){
        return sign > x.sign;
    }
    if (exponent != x.exponent){
        if(sign == -1){
            return exponent < x.exponent;
        }
        else{
            return exponent > x.exponent;
        }
    }
    int size = std::max(Number.size(), x.Number.size());
    std::vector<int> Number1(Number);
    std::vector<int> Number2(x.Number);
	while (int(Number1.size()) != size){
		Number1.push_back(0);
    }
	while (int(Number2.size()) != size){
		Number2.push_back(0);
    }
	for (int i = 0; i < size; i++){
		if (Number1[i] != Number2[i]){
            if(sign == -1){
                return (Number1[i] < Number2[i]);
            }
            else{
                return (Number1[i] > Number2[i]);
            }
        }
    }
	return false;
}

bool LongNumber::operator== (const LongNumber& x) const{
    if (sign == x.sign && exponent == x.exponent && Number == x.Number){
        return true;
    }
    return false;
}

bool LongNumber::operator< (const LongNumber& x) const{
    return !(*this > x || *this == x);
}

bool LongNumber::operator<= (const LongNumber& x) const{
    return (*this < x) || (*this == x);
}

bool LongNumber::operator>= (const LongNumber& x) const{
    return (*this > x) || (*this == x);
}

bool LongNumber::operator!= (const LongNumber& x) const{
    return !(*this == x);
}

LongNumber LongNumber::operator+ (const LongNumber& x) const{
    LongNumber ans;
    if(sign == x.sign){
        ans.sign = sign;
        ans.exponent = std::max(exponent, x.exponent) + 1;

        int exp1 = exponent;
        int exp2 = x.exponent;
        std::vector<int> Number1(Number);
        std::vector<int> Number2(x.Number);
        while (exp1 != ans.exponent){
            Number1.insert(Number1.begin(), 0);
            exp1++;
        }
        while (exp2 != ans.exponent){
            Number2.insert(Number2.begin(), 0);
            exp2++;
        }
        int size = std::max(Number2.size(), Number1.size());
        while (int(Number2.size()) != size){
            Number2.push_back(0);
        }
        while (int(Number1.size()) != size){
            Number1.push_back(0);
        }
        ans.Number = std::vector<int>(size, 0);
        for (int i = 0; i < size; i++){
            ans.Number[i] = Number1[i] + Number2[i];
        }
        for (int i = size - 1; i > 0; i--){
            ans.Number[i - 1] += ans.Number[i] / 10;
            ans.Number[i] = ans.Number[i] % 10;
        }
        ans.remove_zeroes();
        return ans;
    }
	if (x.sign == -1){
		LongNumber ans;
		bool check = *this > -x;
		long exp1 = check ? exponent : x.exponent;
		long exp2 = check ? x.exponent : exponent;
        std::vector<int> Number1(check ? Number : x.Number);
		std::vector<int> Number2(check ? x.Number : Number);
		ans.exponent = std::max(exp1, exp2);
        ans.sign = check ? 1 : -1;

		while (exp1 != ans.exponent) {
			Number1.insert(Number1.begin(), 0);
			exp1++;
		}
		while (exp2 != ans.exponent) {
			Number2.insert(Number2.begin(), 0);
			exp2++;
		}

		int size = std::max(Number1.size(), Number2.size());
		while (int(Number1.size()) != size){
			Number1.push_back(0);
        }
		while (int(Number2.size()) != size){
			Number2.push_back(0);
        }
		ans.Number = std::vector<int>(size + 1, 0);
		for (int i = 0; i < size; i++){
			ans.Number[i + 1] = Number1[i] - Number2[i];
        }
		for (int i = size; i > 0; i--) {
			if (ans.Number[i] < 0) {
				ans.Number[i] += 10;
				ans.Number[i - 1]--;
			}
		}
        ans.exponent++;
		ans.remove_zeroes();
		return ans;
    }
	return x + *this;
}

LongNumber LongNumber::operator- (const LongNumber& x) const{
    return (*this + (-x));
}

LongNumber LongNumber::operator* (const LongNumber& x) const{
    LongNumber ans;
    ans.sign = sign * x.sign;
    ans.exponent = exponent + x.exponent;
    ans.Number = std::vector<int> (Number.size() + x.Number.size(), 0);
    int Num_size = Number.size();
    int x_Num_size = x.Number.size();
    for (int i = 0; i < Num_size; i++){
        for (int j = 0; j < x_Num_size; j++){
            ans.Number[i + j + 1] += Number[i] * x.Number[j];
        }
    }
    for (int i = Number.size() + x.Number.size() - 1; i > 0; i--){
        ans.Number[i - 1] += ans.Number[i] / 10;
        ans.Number[i] = ans.Number[i] % 10;
    }
    ans.remove_zeroes();
    return ans;
}

LongNumber LongNumber::operator/ (const LongNumber& x) const{
    LongNumber inv(x);
    return (*this * inv.inverse_number());
}

std::string LongNumber::LongNumber_to_str(){
    std::string ans = "";
    int exp = exponent;
    if(sign == -1){
        ans += "-";
    }
    if (exp <= 0){
        ans +="0.";
        while(exp < 0){
            exp++;
            ans += '0';
        }
    }
    int Num_size = Number.size();
    for (int i = 0; i < Num_size; i++){
        if (i == exp && i != 0){
            ans += '.';
        }
        ans += char(Number[i] + '0');
    }
    while (Num_size < exp){
        ans += '0';
        exp--;
    }
    return ans;
}