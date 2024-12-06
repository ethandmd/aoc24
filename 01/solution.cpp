#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

int main() {
  uint64_t distance = 0;
  uint64_t similarity = 0;
  std::vector<uint64_t> left, right;
  std::map<uint64_t, uint64_t> freqs;
  std::ifstream infile("input.txt");
  if (!infile.is_open()) {
    std::cout << "Failed to open file" << std::endl;
    return EXIT_FAILURE;
  }

  uint64_t a, b;
  while (infile >> a >> b) {
    left.push_back(a);
    right.push_back(b);
    if (freqs[b]) {
      freqs[b]++;
    } else {
      freqs[b] = 1;
    }
  }
  infile.close();

  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  auto idx = 0;
  auto n = left.size();
  while (idx < n) {
    long d = left[idx] - right[idx];
    distance += std::abs(d);
    auto query = freqs[left[idx]];
    if (query)
      similarity += left[idx] * query;
    idx++;
  }

  std::cout << "Distance is: " << distance << std::endl;
  std::cout << "Similarity is: " << similarity << std::endl;

  return EXIT_SUCCESS;
}
