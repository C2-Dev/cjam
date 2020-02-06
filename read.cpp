#include <fstream>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::ifstream fs;
    std::ofstream out;
    fs.open(argv[1], std::ifstream::in);
    out.open(argv[2]);

    if (!fs.good())
        EXIT_FAILURE;

    char line[1024];
    size_t points;
    int numOfPizzas;

    fs.getline(line, 1024, ' ');
    points = atoi(line);

    fs.getline(line, 1024);
    numOfPizzas = atoi(line);
    
    out << numOfPizzas << ' ' << points << '\n';

    int i = 1;

    while(fs.getline(line,1024,' '))
    {
        out << i << ' ' << atoi(line) << '\n';
        ++i;
    }
    std::cout << "lines read: " << (i - 1) << '\n' << "written to: " << argv[2] << '\n';
}