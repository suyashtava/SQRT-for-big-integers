#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/number.hpp>

using namespace boost::multiprecision;
using namespace std;

int main()
{
   typedef number<cpp_int_backend<2048, 2048, unsigned_magnitude, checked>   uint2048_t;

   /* Square of
   *"91547879977462153546586970079868463514253647575869707906746734142414253764876
     9906896875673562436547859869075464563521421256647689067985784567367478578421"*/

   uint2048_t squared_number(
       "838101432836781587535699121562839931822455187514838272165193522186199333"
       "579126950012125930779673797979163166796552237347578974536543385039486317"
       "240769801830055717088305105313430670551018364460238632111076652604035393"
       "515220692407125770207383372841029867723675432841246997540011854558170082"
       "563012319046853241");

   uint2048_t high = squared_number;
   uint2048_t low  = 1;
   uint2048_t mid;
   uint2048_t val;
   while (low < high)
   {
      mid     = (high + low) / 2;
      val = mid * mid;
      if (val == squared_number)
      {
         break;
      }
      else if (val > squared_number)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   cout << mid << endl;
   return 0;
}
