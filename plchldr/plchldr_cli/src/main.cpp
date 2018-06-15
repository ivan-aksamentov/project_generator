#include <iostream>

#include <boost/bind.hpp>
#include <boost/signals2.hpp>

#include <plchldr/plchldr.h>

// Check whether boost::signals includes, links and runs well
// (it is one of the boost components that requires linking a library)

struct ClassA {
  boost::signals2::signal<void()> sig_a;
  boost::signals2::signal<void(int)> sig_b;
};

struct ClassB {
  void print_day() {
    std::cout << "Today is " << day_of_week_today() << "\n";
  }

  void print_int(int i) {
    std::cout << "Here is some int: " << i << "\n";
  }
};

int main() {
  std::cout << "Hello, this is " << APP_NAME << "\n";

  ClassA a;
  ClassB b, b2;

  a.sig_a.connect(boost::bind(&ClassB::print_day, &b));
  a.sig_b.connect(boost::bind(&ClassB::print_int, &b, _1));
  a.sig_b.connect(boost::bind(&ClassB::print_int, &b2, _1));

  a.sig_a();
  a.sig_b(add(2, 3));

  std::cout << cuda_sum({0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f});
}
