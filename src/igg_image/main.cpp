
#include <iostream>
#include <vector>
#include <string.h>
#include"image.h"
#include "io_tools.h"

using namespace igg;
using namespace io_tools;

using namespace std;

int main()
{
    Image image(5, 6);

    int value = image.at(3, 4);
    int pom = 88;
    image.at(3, 3) = pom;
    cout << "image.at(3, 3) = pom je " << image.at(3, 3) <<endl;
    cout << "jedan element je image.at(3, 4) " << value << endl;
    
    // std::vector<float> vect;
    // vect = image.ComputeHistogram(4);
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<< vect[i] <<endl;
    // }

    bool read = true;
    const string fileName = "../data/lena.ascii.pgm";
    read = image.FillFromPgm(fileName);
    cout <<"read koji je bool kazuje da li je lepo procitano " << read << endl;
    image.UpScale(2);
    image.WriteToPgm("../data/lena.asciiUpScale.pgm");
    return 0;
}
