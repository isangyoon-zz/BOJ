#include <iostream>

int N;
int A[500000];
int B[500000];

long long inversion(int first, int last)
{
  if (first == last) return 0LL;

  int mid = (first + last) / 2;
  long long count = inversion(first, mid) + inversion(mid + 1, last);

  int left = first;
  int right = mid + 1;
  int i = 0;
  while (left <= mid || right <= last)
  {
    if (left <= mid && (right > last || A[left] <= A[right]))
    {
      B[i++] = A[left++];
    }
    else
    {
      count += static_cast<long long>(mid - left + 1);

      B[i++] = A[right++];
    }
  }

  for (auto i = first; i <= last; ++i)
  {
    A[i] = B[i - first];
  }

  return count;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (auto i = 0; i < N; ++i) std::cin >> A[i];

  long long answer = inversion(0, N - 1);
  std::cout << answer << std::endl;

  return 0;
}
