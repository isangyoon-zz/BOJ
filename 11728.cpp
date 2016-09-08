#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

template<typename _RandomAccessIterator, typename _Compare>
void merge(_RandomAccessIterator first, _RandomAccessIterator last, _Compare __comp)
{
  if (last - first > 1)
  {
    _RandomAccessIterator mid = first + (last -first) / 2;

    merge(first, mid, __comp);
    merge(mid, last, __comp);

    std::inplace_merge(first, mid, last, __comp);
  }
}

template<typename _RandomAccessIterator>
void merge(_RandomAccessIterator first, _RandomAccessIterator last)
{
  merge(first, last, std::less<typename std::iterator_traits<_RandomAccessIterator>::value_type>());
}

int N, M;
std::vector<int> A;
std::vector<int> B;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  A.assign(N + M, 0);

  for (auto i = 0; i < N; ++i) std::cin >> A[i];
  for (auto i = N; i < N + M; ++i) std::cin >> A[i];

  merge(std::begin(A), std::end(A));

  std::for_each(std::begin(A), std::end(A), [](int const n) { std::cout << n << " "; });
  std::cout << std::endl;

  return 0;
}
