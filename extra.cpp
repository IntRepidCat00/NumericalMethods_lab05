#include "extra.h"

void SLAR::print()
{
  std::string divideLine(80, '-');

  std::cout << divideLine << std::endl;
  for(int i{0}; i < matrSize; i++)
  {
    for(int j{0}; j < matrSize; j++)
    {
      if(matrA[i][j] >= 0)
      {
        std::cout << "+ " << matrA[i][j] << "x[" << j+1 << "] ";
      } else
      {
        std::cout << "- " << -matrA[i][j] << "x[" << j+1 << "] ";
      }
    }
    if(matrB[i] >= 0)
    {
      std::cout << "= + " << matrB[i] << " ";
    } else
    {
      std::cout << "= - " << -matrB[i] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << divideLine << std::endl;
}

void SLAR::YakobiMethod()
{
  std::cout << "******************** Yakobi method *********************************************" << std::endl;
  std::string divideLine(80, '-');

  std::cout << divideLine << std::endl;

  double matrAl[matrSize][matrSize], matrBl[matrSize];

  for(int i{0}; i < matrSize; i++)
  {
    matrBl[i] = matrB[i]/matrA[i][i];
    for(int j{0}; j < matrSize; j++)
    {
      if(i == j)
      {
        matrAl[i][j] = 0;
      } else
      {
        matrAl[i][j] = -matrA[i][j] / matrA[i][i];
      }
    }
  }

  // Checking convergence
  double maxRowSum{0};

  for(int i{0}; i < matrSize; i++)
  {
    double curRowSum{0};
    for(int j{0}; j < matrSize; j++)
    {
      curRowSum += fabs(matrAl[i][j]);
    }
    if(curRowSum > maxRowSum)
    {
      maxRowSum = curRowSum;
    }
  }
  if(maxRowSum < 1)
  {
    std::cout << "=The iterating process is convergent=" << std::endl;
  } else
  {
    std::cout << "~The iterating process is NOT convergent~" << std::endl;
  }

  std::cout << divideLine << std::endl;

  double matrXPrev[matrSize];
  std::cout << "1) ";
  for(int i{0}; i < matrSize; i++)
  {
    matrX[i] = matrBl[i];
    std::cout << "x[" << i+1 << "] = " <<  matrX[i] << " ";
  }
  std::cout << std::endl;

  double diff{0};
  int iter{1};
  do
  {
    iter++;
    for(int i{0}; i < matrSize; i++)
    {
      matrXPrev[i] = matrX[i];
    }
    std::cout << iter << ") ";
    for(int i{0}; i < matrSize; i++)
    {
      matrX[i] = matrBl[i];
      for(int j{0}; j < matrSize; j++)
      {
        if(i != j)
        {
          matrX[i] += matrAl[i][j]*matrXPrev[j];
        }
      }
      std::cout << "x[" << i+1 << "] = " <<  matrX[i] << " ";
    }
    std::cout << std::endl;
    double curDiff{0};
    diff = 0;
    for(int i{0}; i < matrSize; i++)
    {
      curDiff = fabs(matrX[i] - matrXPrev[i]);
      if(diff < curDiff)
      {
        diff = curDiff;
      }
    }
  } while(diff > eps);

  std::cout << divideLine << std::endl;
}

void SLAR::SeidelMethod()
{
  std::cout << "******************** Seidel method *********************************************" << std::endl;
  std::string divideLine(80, '-');

  std::cout << divideLine << std::endl;

  double matrAl[matrSize][matrSize], matrBl[matrSize];

  for(int i{0}; i < matrSize; i++)
  {
    matrBl[i] = matrB[i]/matrA[i][i];
    for(int j{0}; j < matrSize; j++)
    {
      if(i == j)
      {
        matrAl[i][j] = 0;
      } else
      {
        matrAl[i][j] = -matrA[i][j] / matrA[i][i];
      }
    }
  }

  // Checking convergence
  double maxRowSum{0};

  for(int i{0}; i < matrSize; i++)
  {
    double curRowSum{0};
    for(int j{0}; j < matrSize; j++)
    {
      curRowSum += fabs(matrAl[i][j]);
    }
    if(curRowSum > maxRowSum)
    {
      maxRowSum = curRowSum;
    }
  }
  if(maxRowSum < 1)
  {
    std::cout << "=The iterating process is convergent=" << std::endl;
  } else
  {
    std::cout << "~The iterating process is NOT convergent~" << std::endl;
  }

  std::cout << divideLine << std::endl;

  double matrXPrev[matrSize];
  std::cout << "1) ";
  for(int i{0}; i < matrSize; i++)
  {
    matrX[i] = matrBl[i];
    std::cout << "x[" << i+1 << "] = " <<  matrX[i] << " ";
  }
  std::cout << std::endl;

  double diff{0};
  int iter{1};
  do
  {
    iter++;
    for(int i{0}; i < matrSize; i++)
    {
      matrXPrev[i] = matrX[i];
    }
    std::cout << iter << ") ";
    for(int i{0}; i < matrSize; i++)
    {
      matrX[i] = matrBl[i];
      for(int j{0}; j < matrSize; j++)
      {
        if(j < i)
        {
          matrX[i] += matrAl[i][j]*matrX[j];
        } else if(j > i)
        {
          matrX[i] += matrAl[i][j]*matrXPrev[j];
        }
      }
      std::cout << "x[" << i+1 << "] = " <<  matrX[i] << " ";
    }
    std::cout << std::endl;
    double curDiff{0};
    diff = 0;
    for(int i{0}; i < matrSize; i++)
    {
      curDiff = fabs(matrX[i] - matrXPrev[i]);
      if(diff < curDiff)
      {
        diff = curDiff;
      }
    }
  } while(diff > eps);

  std::cout << divideLine << std::endl;
}