// Copyright 2025 Landon Davidson
// landond@uw.edu

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char **argv) {
  // Allocate an integer on the heap, initialize to value 5.
  // Replace int* with a unique pointer to the int on the heap
  std::unique_ptr<int> x(new int(5));
  std::cout << "*x is: " << *x << std::endl;

  // Allocate a vector of integers on the heap, add some values to
  // that vector, sort the vector, print the values.
  // Replace vector* with unique pointer to the vector on the heap
  std::unique_ptr<std::vector<int>> v(new std::vector<int>);
  v->push_back(13);
  v->push_back(42);
  v->push_back(17);
  std::sort(v->begin(), v->end());
  std::cout << "sorted v: ";
  for (int &el : *v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  // Allocate a vector of (integer pointers) on the stack, add some
  // values to the vector from the heap, print the values.
  // Replace vector<int> with vector<unique_pointer<int>> so we can store unique pointers instead
  std::vector<std::unique_ptr<int>> v2;
  // Replace each int* to the heap with a unique pointer object
  v2.push_back(std::unique_ptr<int>(new int(13)));
  v2.push_back(std::unique_ptr<int>(new int(42)));
  v2.push_back(std::unique_ptr<int>(new int(17)));
  std::cout << "unsorted v2: ";
  // Replace for each loop with an iterator so we aren't copying the unique pointers
  std::vector<std::unique_ptr<int>>::iterator it;
  for (it = v2.begin(); it != v2.end(); it++) {
    std::cout << **it << " ";
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}