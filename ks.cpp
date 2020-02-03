

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>

std::vector<int> w;
std::vector<int> v;
std::vector<std::vector<int>> row;

clock_t timeTaken;

int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    std::cerr << "Not enough args. Usage: ./ks.exe [infile]\n";
    exit(0);
  }

  std::ifstream fs;
  fs.open(argv[1], std::ifstream::in);
  char line[1024];
  int data;

  size_t points;
  int numOfPizzas;

  fs.getline(line, 1024, ' ');
  points = atoi(line);

  fs.getline(line, 1024);
  numOfPizzas = atoi(line);

  timeTaken = clock();

  while (fs.getline(line, 1024, ' '))
  {
    std::cout << line << '\n';
    w.push_back((*line));
  }

  timeTaken -= clock();
  float totalTime = (float)timeTaken / CLOCKS_PER_SEC;

  std::cout
      << "# of pizzas:   " << w.size() << '\n'
      << "# max points:  " << points << '\n'
      << "Read/insert of " << w.size() << " took " << std::setprecision(9) << timeTaken << " s\n";

  for (int i = 0; i < w.size(); ++i)
    std::cout << "w[" << i << "] = " << w[i] << '\n';

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
        row[i][j] = std::max(row[i - 1][j], (v[i] + row[i - 1][j - w[i]]));
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
