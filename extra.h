#ifndef LAB05_EXTRA_H
#define LAB05_EXTRA_H

#include <iostream>
#include <cmath>

class SLAR
{
private:
    double matrA[4][4]
            {
                    {0.65, -0.06, -0.12, 0.14},
                    {0.04, -0.82, 0.08, 0.11},
                    {0.34, 0.08, -0.66, 0.14},
                    {0.11, 0.12, 0,  -0.53}
            };
    double matrX[4]{0, 0, 0, 0};
    double matrB[4]{2.17, -1.4, 2.1, -0.8};
    int matrSize{4};
    double eps{0.001};
public:
    void print();
    void YakobiMethod();
    void SeidelMethod();
};

#endif //LAB05_EXTRA_H
