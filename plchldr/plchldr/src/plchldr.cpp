#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lexical_cast.hpp>


int add(int x, int y) {
  return x + y;
}

// Simple sanity check of one of the boost libraries
// (boost::date requires linking)
std::string day_of_week_today() {
  auto now = boost::posix_time::second_clock::local_time();
  auto today = now.date();
  return boost::lexical_cast<std::string>(today.day_of_week());
}
