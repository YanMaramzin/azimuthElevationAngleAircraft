#include "calculator.h"


double conversionFromDegreesToRadians(double degrees)
{
    return degrees*M_PI/180;
}

double conversionFromRadiansToDegrees(double radians)
{
    return radians*180/M_PI;
}

std::vector<double> getUnitVector(double azimut, double elevationAngle)
{
    std::vector<double> unitVector={cos(elevationAngle)*sin(azimut),
                                    sin(elevationAngle),
                                    cos(elevationAngle)*cos(azimut)
                                   };
    return unitVector;
}

std::vector<double> multiplicationVectorByMatrix(std::vector<double> vec, std::vector<std::vector<double>> matrix)
{

    std::vector<double> multVecMatr(vec.size());
    double sum;
    for(size_t i=0;i<vec.size();i++)
    {
        sum=0;
        for(size_t j=0; j<matrix[0].size();j++)
           sum+=vec[j]*matrix[j][i];
        multVecMatr[i]=sum;
    }
    return multVecMatr;
}

std::vector<double> rotationAroundAxes(double xAngle, double yAngle, double zAngle, std::vector<double>& coord)
{
   std::vector<std::vector<double>> xRotationMatrix= {  { 1, 0, 0},
                                                        { 0, cos(xAngle), sin(xAngle)},
                                                        { 0, -sin(xAngle), cos(xAngle)}};

   std::vector<std::vector<double>> yRotationMatrix={  { cos(yAngle), 0, sin(yAngle)},
                                                       { 0, 1, 0},
                                                       { -sin(yAngle), 0, 0}};
   std::vector<std::vector<double>> zRotationMatrix={  { cos(zAngle), sin(zAngle), 0},
                                                       { -sin(zAngle), cos(zAngle), 0},
                                                       { 0, 0, 1}};
   std::vector<double> newCoord;
   newCoord=multiplicationVectorByMatrix(coord,xRotationMatrix);
   newCoord=multiplicationVectorByMatrix(coord,yRotationMatrix);
   newCoord=multiplicationVectorByMatrix(coord,zRotationMatrix);
   return newCoord;
}
