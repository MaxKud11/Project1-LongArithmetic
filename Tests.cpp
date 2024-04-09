#include<cassert>
#include<iostream>
#include "LongArithmetic.hpp"

void remove_zeroes_test(){
    assert(LongNumber("00000.005000").remove_zeroes() == LongNumber("0.005"));
    assert(LongNumber("50000").remove_zeroes() == LongNumber("50000"));
    std::cout<<"remove_zeroes_test: OK\n";
}

void inverse_number_test(){
    assert(LongNumber("2").inverse_number() == LongNumber("0.5"));
    assert(LongNumber("1000").inverse_number() == LongNumber("0.001"));
    std::cout<<"inverse_number_test: OK\n";
}

void rounding_test(){
    assert(LongNumber("2.00000000").rounding(3) == LongNumber("2.00").rounding(3));
    assert(LongNumber("2").rounding(5) == LongNumber("002.00").rounding(5));
    std::cout<<"rounding_test: OK\n";
}

void negative_test(){
    assert(- LongNumber("700") == LongNumber("-700"));
    assert(- LongNumber("-055.345") == LongNumber("55.345"));
    assert(- LongNumber("123.456") == LongNumber("-123.456"));
    std::cout<<"negative_test: OK\n";
}

void equal_test(){
    assert((LongNumber("-00123.123123") == LongNumber("-123.123123")) == 1);
    assert((LongNumber("1000") == LongNumber("1000")) == 1);
    assert((LongNumber("-00123.123123") == LongNumber("-123.12")) == 0);
    assert((LongNumber("123") == LongNumber("20")) == 0);
    std::cout<<"equal_test: OK\n";
}

void not_equal_test(){
    assert((LongNumber("-00123.123123") != LongNumber("-123.123123")) == 0);
    assert((LongNumber("1000") != LongNumber("1000")) == 0);
    assert((LongNumber("-00123.123123") != LongNumber("-123.12")) == 1);
    assert((LongNumber("123") != LongNumber("20")) == 1);
    std::cout<<"not_equal_test: OK\n";
}

void more_test(){
    assert((LongNumber("-00123.123123") > LongNumber("-123.123123")) == 0);
    assert((LongNumber("1000") > LongNumber("10")) == 1);
    assert((LongNumber("-123") > LongNumber("-17")) == 0);
    assert((LongNumber("123") > LongNumber("20")) == 1);
    std::cout<<"more_test: OK\n";
}

void less_test(){
    assert((LongNumber("-00123.123123") < LongNumber("-123.123123")) == 0);
    assert((LongNumber("1000") < LongNumber("10")) == 0);
    assert((LongNumber("-123") < LongNumber("-17")) == 1);
    assert((LongNumber("123") < LongNumber("20")) == 0);
    std::cout<<"less_test: OK\n";
}

void summ_test(){
    assert(LongNumber("120") + LongNumber("75") == LongNumber("195"));
    assert(LongNumber("11.111") + LongNumber("23.999") == LongNumber("35.11"));
    assert(LongNumber("-11.7") + LongNumber("23.45") == LongNumber("11.75"));
    assert(LongNumber("1000") + LongNumber("-3546") == LongNumber("-2546"));
    std::cout<<"summ_test: OK\n";
}

void difference_test(){
    assert(LongNumber("120") - LongNumber("75") == LongNumber("45"));
    assert(LongNumber("11.111") - LongNumber("23.999") == LongNumber("-12.888"));
    assert(LongNumber("-11.7") - LongNumber("23.45") == LongNumber("-35.15"));
    assert(LongNumber("1000") - LongNumber("-3546") == LongNumber("4546"));
    std::cout<<"difference_test: OK\n";
}

void composition_test(){
    assert(LongNumber("120") * LongNumber("5") == LongNumber("600"));
    assert(LongNumber("11.111") * LongNumber("70") == LongNumber("777.77"));
    assert(LongNumber("-11.7") * LongNumber("130") == LongNumber("-1521"));
    assert(LongNumber("1234.5678") * LongNumber("-8765") == LongNumber("-10820986.767"));
    std::cout<<"composition_test: OK\n";
}

void quotient_test(){
    assert(LongNumber("1") / LongNumber("2") == LongNumber("0.5"));
    assert(LongNumber("150") / LongNumber("50") == LongNumber("3"));
    assert(LongNumber("-123") / LongNumber("10") == LongNumber("-12.3"));
    assert(LongNumber("1000") / LongNumber("64") == LongNumber("15.625"));
    std::cout<<"quotient_test: OK\n";
}

void LongNumber_to_str_test(){
    assert((LongNumber("00.005")).LongNumber_to_str() == "0.005");
    assert(LongNumber("-001723400.00").LongNumber_to_str() == "-1723400");
    assert(LongNumber("12345").LongNumber_to_str() == "12345");
    assert(LongNumber("5.5670").LongNumber_to_str() == "5.567");
    std::cout<<"LongNumber_to_str_test: OK\n";
}

int main(){
    remove_zeroes_test();
    inverse_number_test();
    rounding_test();
    negative_test();
    equal_test();
    not_equal_test();
    more_test();
    less_test();
    summ_test();
    difference_test();
    composition_test();
    LongNumber_to_str_test();
    quotient_test();
    return 0;
}