#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<double>> readFile(string filename)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cerr << "File was not successfully opened.";
        return;
    }
    int n;
    file >> n;
    double[] *all_atoms = new double[n][3];
    for (int i = 0; i < n; i++)
    {
        vector<double> coord;
        for (int j = 0; j < 3; j++)
        {
            double val;
            file >> val;
            coord.push_back(val);
        }
        all_atoms.push_back(coord);
    }
    file.close();
    return all_atoms;
}