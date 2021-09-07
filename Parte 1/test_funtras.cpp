#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>





int main()
{

   cpp_dec_float_50 arg_root = sin_t(3./7) + ln_t(2); 
   
   cpp_dec_float_50 root = root_t(arg_root, 3);
   cpp_dec_float_50 arg_cos = sqrt_t(2);
   cpp_dec_float_50 cos = cos_t(arg_cos);
   cpp_dec_float_50 den = div__t(cos);
   cpp_dec_float_50 res1 = root * den;


   cpp_dec_float_50 pi_ = pi();
   cpp_dec_float_50 exp_ = exp(-1);
   cpp_dec_float_50 log = log_t(exp_, pi_);


   cpp_dec_float_50 res = res1 + log;
   std::cout << "El resultado de la expresion es " << res << "\n";


 
}