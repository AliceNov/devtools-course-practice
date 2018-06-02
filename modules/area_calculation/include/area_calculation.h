// Copyright 2018 Dvorjanchikov Evgeniy

#ifndef MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_
#define MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_

class AreaCalculation {
 public:
    AreaCalculation(int _size, double * x_mas, double * y_mas);
    double GetArea();
    double * GetX();
    double * GetY();
    int GetSize();
    ~AreaCalculation();
 private:
    int FindStart();
    int FindEnd();
    void Transposition();
    double AreaTrapetion(double _first_x, double
    _second_x, double _first_y, double _second_y);
    int size;
    double* x_coordinate;
    double* y_coordinate;
    int first;
    int last;
    double area;
};

#endif  // MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_
