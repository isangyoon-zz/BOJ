#include <iostream>

const int MAX = 1e5;

int N;
int inorder[MAX];
int postorder[MAX];
int indices[MAX + 1];

void reconstruct(int const inorder_first, int const inorder_last, int const postorder_first, int const postorder_last)
{
  if (inorder_first > inorder_last || postorder_first > postorder_last) return;

  int root = postorder[postorder_last];
  std::cout << root << " ";

  int p = indices[root];
  int left = p - inorder_first;
  int right = inorder_last - p;

  reconstruct(inorder_first, p - 1, postorder_first, postorder_first + left - 1);
  reconstruct(p + 1, inorder_last, postorder_first + left, postorder_last - 1);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (auto i = 0; i < N; ++i) std::cin >> inorder[i];
  for (auto i = 0; i < N; ++i) std::cin >> postorder[i];

  for (auto i = 0; i < N; ++i) indices[inorder[i]] = i;

  reconstruct(0, N - 1, 0, N - 1);

  return 0;
}
