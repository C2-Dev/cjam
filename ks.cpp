

#include <iostream>
#include <vector>

size_t points = 17;
int numOfPizzas = 4;

std::vector<int> w = {2, 5, 6, 8};
std::vector<int> v = {1, 2, 3, 4};
std::vector<std::vector<int>> row;
int max(int, int);

int main()
{
  row.resize(numOfPizzas + 1);

  for (int i = 0; i < numOfPizzas + 1; ++i)
    row[i].resize(points + 1, 0);

  for (int i = 1; i <= numOfPizzas; ++i)
  {
    for (size_t j = 0; j <= points; ++j)
    {
      if (w[i] > j)
        row[i][j] = row[i - 1][j];
      else
        row[i][j] = max(row[i - 1][j], (v[i] + row[i - 1][j - w[i]]));
    }
  }

  for (int i = 0; i < numOfPizzas + 1; ++i)
  {
    for (int j = 0; j < points + 1; ++j)
      std::cout << "[" << i << "][" << j << "] = " << row[i][j] << '\n';
  }

  std::cout << "result: " << row[numOfPizzas][points];

  return 0;
}

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}
