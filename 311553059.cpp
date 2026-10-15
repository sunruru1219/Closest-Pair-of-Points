// biker problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double closestInStrip(vector<double> strip_x, vector<double> strip_y, double d) {
    double minDistance = d;
    int s = strip_x.size();

    // Sort the strip by y-coordinates
    for (int i = 0; i < s; ++i) {
        for (int j = i + 1; j < s; ++j) {
            if (strip_y[i] > strip_y[j]) {
                double temp;
                temp = strip_y[i];
                strip_y[i] = strip_y[j];
                strip_y[j] = temp;

                temp = strip_x[i];
                strip_x[i] = strip_x[j];
                strip_x[j] = temp;
            }
        }
    }



    // Compare points in the strip within a window of size d
    for (int i = 0; i < s; ++i) {
        for (int j = i + 1; j < s && (strip_y[j] - strip_y[i]) < minDistance; ++j) {
            double dist = distance(strip_x[i], strip_y[i], strip_x[j], strip_y[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    return minDistance;
}

double count_min(vector<double> loc_x, vector<double> loc_y) {
    double minD;

    // if less than 2 points, count the min distance
    if (loc_x.size() == 1) return 1000.0;
    if (loc_x.size() == 2) return distance(loc_x[0], loc_y[0], loc_x[1], loc_y[1]);
    

    // else cut into half
    int middle = loc_x.size() / 2;
    vector<double> leftHalf_x(loc_x.begin(), loc_x.begin() + middle);
    vector<double> rightHalf_x(loc_x.begin() + middle, loc_x.end());
    vector<double> leftHalf_y(loc_y.begin(), loc_y.begin() + middle);
    vector<double> rightHalf_y(loc_y.begin() + middle, loc_y.end());
    double leftMin = count_min(leftHalf_x, leftHalf_y);
    double rightMin = count_min(rightHalf_x, rightHalf_y);
    minD = min(leftMin, rightMin);

    vector<double> strip_x;
    vector<double> strip_y;
    for (int i = 0; i < loc_x.size(); ++i) {
        if (abs(loc_x[i] - loc_x[middle]) < minD) {
            strip_x.push_back(loc_x[i]);
            strip_y.push_back(loc_y[i]);
        }
    }
  
    double minStrip = closestInStrip(strip_x, strip_y, minD);
    // Find the minimum distance within the strip

    return min(minD, minStrip);
}






int main()
{
    int T; // number of cases
    //cout << "Number of cases: ";
    cin >> T;

    // go through each case
    for (int i = 0; i < T; ++i) {
        int n; // number of photographers
        //cout << "Number of photographers: ";
        cin >> n;
        vector<double> loc_x; // (x1, x2, x3, ...)
        vector<double> loc_y; // (y1, y2, y3, ...)

        // input the coordinates, sorted by x
        //cout << "Coordinates: ";
        double x, y;
        cin >> x >> y;
        loc_x.push_back(x);
        loc_y.push_back(y);
        for (int j = 0; j < n-1; ++j) {
            // int x, y;
            cin >> x >> y;
            //count += 1;
            loc_x.push_back(x);
            loc_y.push_back(y);
            
            for (int k = loc_x.size() - 1; (k > 0 && loc_x[k-1] > x); --k) {
                double temp;
                temp = loc_x[k];
                loc_x[k] = loc_x[k - 1];
                loc_x[k - 1] = temp;
                
                temp = loc_y[k];
                loc_y[k] = loc_y[k - 1];
                loc_y[k - 1] = temp;
            }
        }

        double minD = count_min(loc_x, loc_y);
        cout << minD << endl;
    }
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
