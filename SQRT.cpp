{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.18362}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs22\lang9 #include <iostream>\par
\par
#include <boost/multiprecision/cpp_int.hpp>\par
#include <boost/multiprecision/number.hpp>\par
\par
using namespace boost::multiprecision;\par
using namespace std;\par
\par
int main()\par
\{\par
   typedef number<cpp_int_backend<2048, 2048, unsigned_magnitude, checked>   uint2048_t;\par
\par
   /* Square of\par
   *"91547879977462153546586970079868463514253647575869707906746734142414253764876\par
     9906896875673562436547859869075464563521421256647689067985784567367478578421"*/\par
\par
   uint2048_t squared_number(\par
       "838101432836781587535699121562839931822455187514838272165193522186199333"\par
       "579126950012125930779673797979163166796552237347578974536543385039486317"\par
       "240769801830055717088305105313430670551018364460238632111076652604035393"\par
       "515220692407125770207383372841029867723675432841246997540011854558170082"\par
       "563012319046853241");\par
\par
   uint2048_t high = squared_number;\par
   uint2048_t low  = 1;\par
   uint2048_t mid;\par
   uint2048_t val;\par
   while (low < high)\par
   \{\par
      mid     = (high + low) / 2;\par
      val = mid * mid;\par
      if (val == squared_number)\par
      \{\par
         break;\par
      \}\par
      else if (val > squared_number)\par
      \{\par
         high = mid - 1;\par
      \}\par
      else\par
      \{\par
         low = mid + 1;\par
      \}\par
   \}\par
   cout << mid << endl;\par
   return 0;\par
\}\par
}
 