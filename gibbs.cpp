#include <Rcpp.h>
using namespace Rcpp;
 
// [[Rcpp::export]]
NumericMatrix gibbs(int N, int thin) {
 
   NumericMatrix mat(N, 2);
   double x = 0, y = 0;
 
   RNGScope scope;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < thin; j++) {
         x = R::rgamma(3.0, 1.0 / (y * y + 4));
         y = R::rnorm(1.0 / (x + 1), 1.0 / sqrt(2 * x + 2));
      }
      mat(i, 0) = x;
      mat(i, 1) = y;
   }
 
   return(mat);
}

/*** R
gibbs(1000, 200)
*/
