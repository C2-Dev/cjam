

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
  char line[2048];
  int data;

  std::string test;
  size_t points;
  int numOfPizzas;

  fs.getline(line, 1024, ' ');
  points = atoi(line);

  fs.getline(line, 1024);
  numOfPizzas = atoi(line);

  timeTaken = clock();

  int c;
  std::string str;

  while (fs.getline(line, 1024, ' '))
  {
    w.push_back(atoi(line));
  }

  timeTaken -= clock();
  float totalTime = (float)timeTaken / CLOCKS_PER_SEC;

  std::cout
      << "# of pizzas:   " << w.size() << '\n'
      << "# max points:  " << points << '\n'
      << "Read/insert of " << w.size() << " took " << std::setprecision(9) << timeTaken << " s\n";

  v.resize(w.size(), 0);

  printf("v.size(): %lu\n", v.size());

  for (size_t i = 0; i < v.size(); ++i)
    v[i] = i;
  
  row.resize(w.size() + 1);

  for (size_t i = 0; i < (w.size() + 1); ++i)
    row[i].resize((points + 1), 0);

  printf("row.size(): %lu\n", row.size());
  printf("row[0].size(): %lu\n", row[0].size());

  for (size_t i = 1; i <= w.size(); ++i)
  {
    for (size_t j = 0; j <= points; ++j)
    {
      printf("w[%lu][%lu]\n", i,j);
      if (w[i] > j)
        row[i][j] = row[i - 1][j];
      else
        row[i][j] = std::max(row[i - 1][j], (v[i] + row[i - 1][j - w[i]]));
    }
  }
  /*
  for (size_t i = 0; i < (w.size() + 1); ++i)
  {
    for (size_t j = 0; j < (points + 1); ++j)
    {
      if ((j == points))
      {
        std::cout << row[i][j] << '\n';
        break;
      }
      std::cout << row[i][j] << ' ';
    }
  }*/
  
  std::cout << row[w.size()][points];

  fs.close();

  return 0;
}
