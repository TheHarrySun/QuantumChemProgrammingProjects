#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double bondLength(double *atom1, double *atom2)
{
    cout << atom2[2] << endl;
    cout << sizeof(atom1) << " " << sizeof(atom1[0]) << endl;
    cout << sizeof(*atom1) / sizeof(atom1[0]) << endl;
    if (sizeof(atom1) / sizeof(atom1[0]) != 3 || sizeof(atom2) / sizeof(atom2[0]) != 3)
    {
        cerr << "Atoms must have three coordinates: x, y, and z." << endl;
        exit(1);
    }
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += pow(atom1[i] - atom2[i], 2);
    }
    return sqrt(sum);
}

int main(int argc, char *argv[])
{
    cout << argc << endl;
    if (argc <= 1)
    {
        cerr << "File Must Be Inputted" << endl;
        return 1;
    }
    ifstream file;
    string filename = argv[1];
    cout << filename << endl;
    file.open(filename);
    if (!file.is_open())
    {
        cerr << "File is not successfully opened." << endl;
    }
    int n;
    file >> n;
    double coords[n][3];
    int zscores[n];
    for (int i = 0; i < n; i++)
    {
        int z;
        file >> z;
        zscores[i] = z;
        cout << zscores[i] << " ";
        for (int j = 0; j < 3; j++)
        {
            double coord;
            file >> coord;
            coords[i][j] = coord;
            cout << coords[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
    cout << bondLength(coords[0], coords[1]);
}