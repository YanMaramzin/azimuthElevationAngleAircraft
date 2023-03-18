#include "calculator.h"


double conversionFromDegreesToRadians(double degrees)
{
    return degrees*M_PI/180;
}

double conversionFromRadiansToDegrees(double radians)
{
    return radians*180/M_PI;
}

std::vector<std::vector<double>> getUnitVector(double azimut, double elevationAngle)
{
    std::vector<std::vector<double>> unitVector={{cos(elevationAngle)*sin(azimut)},
                                    {sin(elevationAngle)},
                                    {cos(elevationAngle)*cos(azimut)}
                                   };
    return unitVector;
}



std::vector<std::vector<double>> multiplicationVectorByMatrix(std::vector<std::vector<double>>& matrix,std::vector<std::vector<double>>& vec)
{

   std::vector<std::vector<double>> multVecMatr(vec.size(),std::vector<double>(1));
   for(size_t row=0;row<3;row++)
   {
       for(size_t col=0; col<3;col++)
          for(size_t inner=0;inner<3;inner++)
            multVecMatr[row][col]+=matrix[row][inner] * vec[inner][0];

   }
   return multVecMatr;
}


std::vector<std::vector<double>> rotationAroundAxes(double xAngle, double yAngle, double zAngle,  std::vector<std::vector<double>>& coord)
{
  std::vector<std::vector<double>> xRotationMatrix= {  { 1, 0, 0},
                                                       { 0, cos(xAngle), -sin(xAngle)},
                                                       { 0, sin(xAngle), cos(xAngle)}};

  std::vector<std::vector<double>> yRotationMatrix={  { cos(yAngle), 0, sin(yAngle)},
                                                      { 0, 1, 0},
                                                      { -sin(yAngle), 0, cos(yAngle)}};
  std::vector<std::vector<double>> zRotationMatrix={  { cos(zAngle), -sin(zAngle), 0},
                                                      {sin(zAngle), cos(zAngle), 0},
                                                      { 0, 0, 1}};
  std::vector<std::vector<double>> newCoord;
  newCoord=multiplicationVectorByMatrix(xRotationMatrix,coord);
  newCoord=multiplicationVectorByMatrix(yRotationMatrix,newCoord);
  newCoord=multiplicationVectorByMatrix(zRotationMatrix,newCoord);
  return newCoord;
}
