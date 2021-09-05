#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>





int main()
{



   //cpp_dec_float_50 res = div_ta(100);
   cpp_dec_float_50 res1 = exp_t(-1);
   //cpp_dec_float_50 res2 = sin_t(25);
   //cpp_dec_float_50 res3 = cos_t(-40);
   //cpp_dec_float_50 res4 = tan_t(20);
   //cpp_dec_float_50 res5 = ln_t(98);
   //cpp_dec_float_50 res6 = log_t(75,3);
   //cpp_dec_float_50 res7 = power_t(-5, 7);
   //cpp_dec_float_50 res8 = pi();
   cpp_dec_float_50 res9 = sqrt_t(2);
   //cpp_dec_float_50 res10 = root_t(6,3);
   //cpp_dec_float_50 res11 = asin_t(0.23);

    //std::cout << "div_t " << res << '\n';
    //std::cout << "exp " << res1 << '\n';
    //std::cout << "sin " <<res2 << '\n';
    //std::cout << "cos " <<res3 << '\n';
    //std::cout << "tan " <<res4 << '\n';
    //std::cout << "ln " <<res5 << '\n';
    //std::cout << "log " <<res6 << '\n';
    //std::cout << "power "<<res7 << '\n';
    //std::cout << "pi "<<res8 << '\n';
    //std::cout << "sqrt "<<res9 << '\n';
    //std::cout << "root "<<res10 << '\n';
    //std::cout << "asin "<<res11 << '\n';



   cpp_dec_float_50 r1 = sin_t(3./7) + ln_t(2); 
   std::cout << r1  << "\n";



   cpp_dec_float_50 r11 = root_t(r1, 3);
   std::cout << r11  << "\n";



   cpp_dec_float_50 r2 = cos_t(res9);
   std::cout << r2  << "\n";



   cpp_dec_float_50 pi_ = pi();
   std::cout << pi_  << "\n";



   cpp_dec_float_50 r3 = log_t(res1, pi_);
   std::cout << r3  << "\n";


   cpp_dec_float_50 final = (r11 / r2) + r3;
   std::cout << final << "\n";
 
}