

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


    while(fs.getline(line,1024,' '))
    {
       w.push_back(atoi(line));
    }

  timeTaken -= clock();
  float totalTime = (float)timeTaken / CLOCKS_PER_SEC;

  std::cout
      << "# of pizzas:   " << w.size() << '\n'
      << "# max points:  " << points << '\n'
      << "Read/insert of " << w.size() << " took " << std::setprecision(9) << timeTaken << " s\n";

  for (int i = 0; i < w.size(); ++i)
    std::cout << "w[" << i << "] = " << w[i] << '\n';

  fs.close();
 
  return 0;
}
