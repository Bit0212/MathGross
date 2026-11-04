#include <iostream>
// Use with caution!
//  constantin is important for the deepness in the precision of some constants!
//   wtf is a constant required to make pi(not kidding)
constexpr int constantin = 1000;
constexpr long double wtf = 0.00456621004;
template <typename T> T fac(int a) {
  T termediare{1};
  for (; a > 0; a--) {
    termediare *= a;
  }
  return static_cast<T>(termediare);
}

template <typename T> constexpr T stresspow(T expr, int a) {
  T p{1};
  for (std::size_t i = 0; i < static_cast<std::size_t>(a); i++) {
    p *= expr;
  }
  return p;
}
consteval long double euler(int x) {

  long double superxpr = (1.0 + (1.0 / x));

  return stresspow<long double>(superxpr, x);
}
constexpr long double lnat(int x) {

  auto imparem_gen = [](int x) {
    // 2n+1;
    return (2 * x) + 1;
  };
  double z = (static_cast<double>(x) - 1) / (static_cast<double>(x) + 1);
  double anatoli{};
  for (std::size_t i = 0; i < constantin; i++) {
    anatoli += (stresspow<double>(z, imparem_gen(i)) / imparem_gen(i));
  }
  anatoli *= 2;
  return anatoli;
}

long double taytay(long double traismos) {
  long double strassbourg{0};
  for (int i = 0; i < constantin; i++) {
    strassbourg += (stresspow<long double>(traismos, i) / fac<long double>(i));
  }
  return strassbourg;
}

consteval int fib(int a) {
  int ayudant{};
  if (a == 1 || a == 0) {
    if (a == 1)
      return 1;
    else
      return 0;
  }
  /*auto x =[&ayudant, &a](){
  for(std::size_t contador=0; contador<a; contador++){
  ayudant+=contador;
  }
  return ayudant;
  };*/

  return fib(a - 2) + fib(a - 1);
}
long double truepow(long double x, long double y) {
  return taytay(y * lnat(x));
}
long double arctangent(long double x) {
  long double upper{};
  long double dowpper{};
  long double totale{};
  for (int i = 0; i < constantin; i++) {
    upper = stresspow((-1), i) * (stresspow<long double>(x, ((2 * i) + 1)));
    dowpper = (2 * i) + 1;
    totale += upper / dowpper;
  }
  return totale;
}
const auto pi =
    (static_cast<long double>(16) * arctangent(static_cast<long double>(0.20)) -
     (static_cast<long double>(4) * arctangent(wtf)));
int main() {
  // use fib function wisely! it goes deep in recursion!
  //  constexpr auto fib5 = fib(30);
  // std::cout << fib5 << std::endl;
  // some examples of the implementation
  std::cout << static_cast<double>(euler(80));
  std::cout << "\n" << truepow(5, 2);
  std::cout.precision(15);
  std::cout << "\n" << pi << "\n";
  std::cout << truepow(7, 3);
  return 0;
}
