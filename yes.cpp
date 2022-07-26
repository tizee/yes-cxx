#include <iostream>
#include <streambuf>


int main(int argc, const char **argv) {
  auto output = argc > 1 ? argv[1] : "y";

  static const auto f = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    return 0;
  }();
  while (true) {
    std::cout << output << "\n";
  }
  return 0;
}
