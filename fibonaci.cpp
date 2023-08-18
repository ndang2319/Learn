#include <iostream>
#include <vector>

int fibonaci(int number, std::vector<int> &result) {
  if (number < result.size()) {
    return result[number];
  }

  result.push_back(fibonaci(number, result));

  return result[number];
}

int int main(int argc, char const *argv[])
{
  std::vector<int> result {0, 1};
  fibonaci(1, result);
  return 0;
}

