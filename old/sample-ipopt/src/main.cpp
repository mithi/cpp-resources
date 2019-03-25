# include <cppad/ipopt/solve.hpp>

/*
 * SOURCE: https://www.coin-or.org/CppAD/Doc/ipopt_solve_get_started.cpp.htm 
 * 
 *  1. minimize cost function: x0 * x3 * (x0 + x1 + x2) + x2
 *
 *  2. subject to the following constraints:
 *     (A) x0 * x1 * x2 * x3 >= 25
 *     (B) x0^2 + x1^2 + x2^2 + x3^2 = 40
 *     (C) 1 <= x0, x1, x2, x3 <= 5
 *
 */


using CppAD::AD;

class FG_eval {

  public:

    typedef CPPAD_TESTVECTOR(AD<double>) ADvector;
    FG_eval(){};
    void operator()(ADvector& fg, const ADvector& x){
      
      assert(fg.size() == 3);
      assert(x.size() == 4);

      AD<double> x0 = x[0];
      AD<double> x1 = x[1];
      AD<double> x2 = x[2];
      AD<double> x3 = x[3];

      //cost function to minimize
      fg[0] = x0 * x3 * (x0 + x1 + x2) + x2;

      // g0 --> function for constraint (A)
      fg[1] = x0 * x1 * x2 * x3;

      // g1 --> function for constraint (B)
      fg[2] = x0 * x0 + x1 * x1 + x2 * x2 + x3 * x3;

      return;
    } 
};

int main(){

  typedef CPPAD_TESTVECTOR(double) Dvector;

  const int nx = 4; // number of independent variables (x0, x1, x2, x3)
  const int ng = 2; // number of function constraint (g0, g1)

  // set initial values of independent variables
  Dvector start_x(nx); 

  start_x[0] = 1.0;
  start_x[1] = 5.0;
  start_x[2] = 5.0;
  start_x[3] = 1.0;

  // set lower and upper limit for independent variables
  Dvector lowerlimit_x(nx);
  Dvector upperlimit_x(nx);

  for(int i = 0; i < nx; ++i){
    lowerlimit_x[i] = 1.0;
    upperlimit_x[i] = 5.0;
  }

  // set lower and upperlimit for each contraint function g0, g1
  Dvector lowerlimit_g(ng);
  Dvector upperlimit_g(ng);

  upperlimit_g[0] = 1.0e19;
  lowerlimit_g[0] = 25.0;
  
  upperlimit_g[1] = 40.0;
  lowerlimit_g[1] = 40.0;

  // instantiate object that computes objective and constraints
  FG_eval fg_eval;

  // OPTIONS
  std::string options;
  // turn off any printing
  options += "Integer print_level  0\n";
  options += "String  sb           yes\n";
  // maximum number of iterations
  options += "Integer max_iter     10\n";
  // approximate accuracy in first order necessary conditions;
  // see Mathematical Programming, Volume 106, Number 1,
  // Pages 25-57, Equation (6)
  options += "Numeric tol          1e-6\n";
  // derivative testing
  options += "String  derivative_test            second-order\n";
  // maximum amount of random pertubation; e.g.,
  // when evaluation finite diff
  options += "Numeric point_perturbation_radius  0.\n";

  // object to return solution
  CppAD::ipopt::solve_result<Dvector> solution;

  // solve the problem
  CppAD::ipopt::solve<Dvector, FG_eval>(
    options, 
    start_x, 
    lowerlimit_x, 
    upperlimit_x, 
    lowerlimit_g, 
    upperlimit_g, 
    fg_eval, 
    solution);

  // check some of the solution values
  bool ok = true;
  ok &= solution.status == CppAD::ipopt::solve_result<Dvector>::success;

  double check_x[]  = { 1.000000, 4.743000, 3.82115, 1.379408 };
  double check_zl[] = { 1.087871, 0.,       0.,      0.       };
  double check_zu[] = { 0.,       0.,       0.,      0.       };
  double rel_tol    = 1e-6;  // relative tolerance
  double abs_tol    = 1e-6;  // absolute tolerance
  
  for(int i = 0; i < nx; ++i){
    ok &= CppAD::NearEqual(check_x[i],  solution.x[i],   rel_tol, abs_tol);
    ok &= CppAD::NearEqual(check_zl[i], solution.zl[i], rel_tol, abs_tol);
    ok &= CppAD::NearEqual(check_zu[i], solution.zu[i], rel_tol, abs_tol);
  }

  if (ok) {
    std::cout << "Test passed! :)" << std::endl;
  }

  return 0;
}
