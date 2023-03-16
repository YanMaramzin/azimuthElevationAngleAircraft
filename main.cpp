#include <iostream>
#include <cmath>
#include <vector>

/*  Задача №2
    Пеленгатор размещен на летательном аппарате. Известны углы курса, крена и тангажа.
    Для рассчитанного направления (азимут угол места) относительно АФС-П (азимут и угол места нам даны), необходимо рассчитать
    направление относительно земли. (Выполнить повороты, относительно осей)
 */


double conversionFromDegreesToRadians(double degrees);
std::vector<double> getUnitVector(double azimut, double elevationAngle);
std::vector<double> rotationAroundAxes(double xAngle, double yAngle, double zAngle, std::vector<double>& coord);
std::vector<double> multiplicationVectorByMatrix(std::vector<double> vec, std::vector<std::vector<double>> matrix);
double conversionFromRadiansToDegrees(double radians);



int main()
{
    double pitchAngle;                  //угол тангажа
    double bankAngle;                   //угол крена
    double headingAngle;                //угол курса
    double azimuthRelativeAFSP;         //азимут относительно АФС-П
    double elevationAngleRelativeAFSP;  //угол места относительно АФС-П


    std::cout<<"Введите значение азимута относительно АФС-П от 0 до 360 градусов: ";
    std::cin>>azimuthRelativeAFSP;
    azimuthRelativeAFSP=conversionFromDegreesToRadians(azimuthRelativeAFSP);

    std::cout<<"Введите угол места относительно АФС-П от -90 до 90 градусов: ";
    std::cin>>elevationAngleRelativeAFSP;
    elevationAngleRelativeAFSP=conversionFromDegreesToRadians(elevationAngleRelativeAFSP);

    //Ввод необходимых данных для рассчета
    std::cout<<"Введите значение угла тангажа: ";
    std::cin>>pitchAngle;
    pitchAngle=conversionFromDegreesToRadians(-pitchAngle);

    std::cout<<"Введите значение угла крена: ";
    std::cin>>bankAngle;
    bankAngle=conversionFromDegreesToRadians(bankAngle);

    std::cout<<"Введите значение угла курса: ";
    std::cin>>headingAngle;
    headingAngle=conversionFromDegreesToRadians(-headingAngle);

    std::vector<double> unitVector=getUnitVector(azimuthRelativeAFSP,elevationAngleRelativeAFSP);


    unitVector=rotationAroundAxes(pitchAngle,bankAngle,headingAngle,unitVector);

    double azimuthOverGround=-atan(unitVector[0]/unitVector[1]);
    double elevationAngleRelativeGround=M_PI-atan(sqrt(unitVector[0]*unitVector[0]+unitVector[1]*unitVector[1])/unitVector[3]);

    std::cout<<"Азимут: "<<conversionFromRadiansToDegrees(azimuthOverGround)<<" в градусах\n";
    std::cout<<"Угол места: "<<conversionFromRadiansToDegrees(elevationAngleRelativeGround)<<" в градусах\n";

    return 0;
}

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
