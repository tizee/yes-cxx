#include <cstring>
#include <iostream>

constexpr size_t BUF_CAP = 8 * (1 << 10);

size_t fillBuffer(char *buf, char const *output) {
  size_t output_size = strlen(output);
  if (output_size > BUF_CAP / 2) {
    return output_size;
  }

  memcpy(buf, output, std::strlen(output));
  memcpy(buf + output_size, "\n", 1);
  size_t buf_size = output_size + 1;
  while (buf_size < BUF_CAP / 2) {
    memcpy(buf + buf_size, buf, buf_size);
    buf_size *= 2;
  }
  return buf_size;
}

int main(int argc, char const **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  char buf[BUF_CAP];
  char const *output = argc > 1 ? argv[1] : "y";
  size_t buf_size = fillBuffer(buf, output);

  while (true) {
    std::cout.write(buf, buf_size);
  }
  return 0;
}
