#include <iostream>
#include <algorithm>
#include <map>

int N;
std::map<char, std::pair<char, char> > T;

void preorder(char root)
{
  if (root == '.') return;

  std::cout << root;
  preorder(T[root].first);
  preorder(T[root].second);
}

void inorder(char root)
{
  if (root == '.') return;

  inorder(T[root].first);
  std::cout << root;
  inorder(T[root].second);
}

void postorder(char root)
{
  if (root == '.') return;

  postorder(T[root].first);
  postorder(T[root].second);
  std::cout << root;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  while (N--)
  {
    char parent, left, right;
    std::cin >> parent >> left >> right;

    T[parent] = {left, right};
  }

  preorder('A');
  std::cout << std::endl;

  inorder('A');
  std::cout << std::endl;

  postorder('A');
  std::cout << std::endl;

  return 0;
}
