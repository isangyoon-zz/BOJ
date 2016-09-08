#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

const double PI = std::acos(-1.0);

int N, M;
std::vector<bool> check(200001, false);
std::vector<std::complex<double>> distances(1 << 20, std::complex<double>(0.0, 0.0));

int reverse(int index, std::size_t size)
{
  int result = 0;
  for (auto i = 0; (1 << i) < size; ++i)
  {
    result <<= 1;

    if (index & (1 << i)) result |= 1;
  }

  return result;
}

std::vector<std::complex<double>> A(1 << 20, std::complex<double>(0.0, 0.0));
void FFT(std::vector<std::complex<double>>& a, std::size_t size, int DFT)
{
  for (auto i = 0; i < size; ++i)
  {
    A[reverse(i, size)] = a[i];
  }

  for (auto i = 1; (1 << i) <= size; ++i)
  {
    int mask = (1 << i);
    std::complex<double> wm(std::cos(DFT * 2 * PI / mask), std::sin(DFT * 2 * PI / mask));

    for (auto j = 0; j < size; j += mask)
    {
      std::complex<double> w(1.0, 0.0);

      for (auto k = 0; k < (mask >> 1); ++k)
      {
        std::complex<double> t = w * A[j + k + (mask >> 1)];
        std::complex<double> s = A[j + k];

        A[j + k] = s + t;
        A[j + k + (mask >> 1)] = s - t;

        w *= wm;
      }
    }
  }

  if (DFT == -1)
  {
    for (auto i = 0; i < size; ++i)
    {
      A[i].real(A[i].real() / size);
      A[i].imag(A[i].imag() / size);
    }
  }

  for (auto i = 0; i < size; ++i)
  {
    a[i] = A[i];
  }
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (std::cin >> N)
  {
    std::fill(std::begin(check), std::end(check), false);

    int max = 0;
    for (auto i = 0; i < N; ++i)
    {
      int d;
      std::cin >> d;

      check[d] = true;
      max = std::max(max, d);
    }

    for (auto i = 0; i <= max; ++i)
    {
      distances[i] = std::complex<double>((check[i]) ? 1.0 : 0.0, 0.0);
    }

    std::size_t size = 1;
    while (max >= size) size <<= 1;
    size <<= 1;

    for (auto i = max + 1; i < size; ++i)
    {
      distances[i] = std::complex<double>(0.0, 0.0);
    }

    FFT(distances, size, 1);

    for (auto i = 0; i < size; ++i)
    {
      distances[i] = distances[i] * distances[i];
    }

    FFT(distances, size, -1);

    std::cin >> M;

    int answer = 0;
    for (auto i = 0; i < M; ++i)
    {
      int d;
      std::cin >> d;

      if (max * 2 >= d && (distances[d].real() > 0.5 || check[d])) ++answer;
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
