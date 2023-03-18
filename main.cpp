#include <iostream>
#include <cmath>
#include <vector>
#include "calculator.h"

/*  Задача №2
    Пеленгатор размещен на летательном аппарате. Известны углы курса, крена и тангажа.
    Для рассчитанного направления (азимут угол места) относительно АФС-П (азимут и угол места нам даны), необходимо рассчитать
    направление относительно земли. (Выполнить повороты, относительно осей)
 */

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
    pitchAngle=conversionFromDegreesToRadians(pitchAngle);

    std::cout<<"Введите значение угла крена: ";
    std::cin>>bankAngle;
    bankAngle=conversionFromDegreesToRadians(bankAngle);

    std::cout<<"Введите значение угла курса: ";
    std::cin>>headingAngle;
    headingAngle=conversionFromDegreesToRadians(headingAngle);

    std::vector<std::vector<double>> unitVector=getUnitVector(azimuthRelativeAFSP,elevationAngleRelativeAFSP);


    unitVector=rotationAroundAxes(-pitchAngle,bankAngle,-headingAngle,unitVector);

    double azimuthOverGround=-atan(unitVector[0][0]/unitVector[1][0]);
    double elevationAngleRelativeGround=M_PI-atan(sqrt(unitVector[0][0]*unitVector[0][0]+unitVector[1][0]*unitVector[1][0])/unitVector[2][0]);

    std::cout<<"Азимут: "<<conversionFromRadiansToDegrees(azimuthOverGround)<<" в градусах\n";
    std::cout<<"Угол места: "<<conversionFromRadiansToDegrees(elevationAngleRelativeGround)<<" в градусах\n";

    return 0;
}


