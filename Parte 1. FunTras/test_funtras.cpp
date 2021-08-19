#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>




void print_factorials()
{
   using boost::multiprecision::cpp_int;
   //
   // Print all the factorials that will fit inside a 128-bit integer.
   //
   // Begin by building a big table of factorials, once we know just how
   // large the largest is, we'll be able to "pretty format" the results.
   //
   // Calculate the largest number that will fit inside 128 bits, we could
   // also have used numeric_limits<int128_t>::max() for this value:
   cpp_int limit = (cpp_int(1) << 128) - 1;
   //
   // Our table of values:
   std::vector<cpp_int> results;
   //
   // Initial values:
   unsigned i = 1;
   cpp_int factorial = 1;
   //
   // Cycle through the factorials till we reach the limit:
   while(factorial < 100)
   {
      results.push_back(factorial);
      ++i;
      factorial *= i;
   }
   //
   // Lets see how many digits the largest factorial was:
   unsigned digits = results.back().str().size();
   //
   // Now print them out, using right justification, while we're at it
   // we'll indicate the limit of each integer type, so begin by defining
   // the limits for 16, 32, 64 etc bit integers:
   cpp_int limits[] = {
      (cpp_int(1) << 16) - 1,
      (cpp_int(1) << 32) - 1,
      (cpp_int(1) << 64) - 1,
      (cpp_int(1) << 128) - 1,
   };
   std::string bit_counts[] = { "16", "32", "64", "128" };
   unsigned current_limit = 0;
   for(unsigned j = 0; j < results.size(); ++j)
   {
      if(limits[current_limit] < results[j])
      {
         std::string message = "Limit of " + bit_counts[current_limit] + " bit integers";
         std::cout << std::setfill('.') << std::setw(digits+1) << std::right << message << std::setfill(' ') << std::endl;
         ++current_limit;
      }
      std::cout << std::setw(digits + 1) << std::right << results[j] << std::endl;
   }
}

int main()
{


    //print_factorials();
    double res = div_ta(5);
    double res1 = exp_t(6);
    double res2 = sin(75);
    double res3 = cos(-80);
    double res4 = tan(0.34);
    double res5 = ln_t(98);
    double res6 = log_t(75,3);
    double res7 = power_t(2, 8);
    double res8 = pi();
    double res9 = sqrt_t(6);
    double res10 = root_t(6,3);
    double res11 = asin_t(0.23);

    std::cout << "div_t " << res << '\n';
    std::cout << "exp " << res1 << '\n';
    std::cout << "sin " <<res2 << '\n';
    std::cout << "cos " <<res3 << '\n';
    std::cout << "tan " <<res4 << '\n';
    std::cout << "ln " <<res5 << '\n';
    std::cout << "log " <<res6 << '\n';
    std::cout << "power "<<res7 << '\n';
    std::cout << "pi "<<res8 << '\n';
    std::cout << "sqrt "<<res9 << '\n';
    std::cout << "root "<<res10 << '\n';
    std::cout << "asin "<<res11 << '\n';
 
}