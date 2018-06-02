// Copyright 2018 Dvorjanchikov Evgeniy
#include <math.h>
#include "include/area_calculation.h"

AreaCalculation::AreaCalculation(int _size, double * x_mas, double * y_mas) {
    size = _size;
    area = 0;
    x_coordinate = new double[size];
    y_coordinate = new double[size];
    for (int i = 0; i < size; i++) {
        x_coordinate[i] = x_mas[i];
        y_coordinate[i] = y_mas[i];
    }
}

double AreaCalculation::GetArea() {
    if (area > 0) {
    return area;
    } else {
        Transposition();
        double up_area = 0;
        double down_area = 0;
        int cur_step = first;
        while (cur_step != last) {
            int tmp = cur_step;
            if (cur_step != size-1)
                cur_step++;
            else
                cur_step = 0;
            up_area += AreaTrapetion(x_coordinate[tmp], x_coordinate[cur_step],
            y_coordinate[tmp], y_coordinate[cur_step]);
        }
        cur_step = last;
        while (cur_step != first) {
            int tmp = cur_step;
            if (cur_step != size-1)
                cur_step++;
            else
                cur_step = 0;
            down_area += AreaTrapetion(x_coordinate[tmp],
            x_coordinate[cur_step],
            y_coordinate[tmp], y_coordinate[cur_step]);
        }
        area = fabs(up_area - down_area);
        return area;
    }
}

double * AreaCalculation::GetX() {
    return x_coordinate;
}

double * AreaCalculation::GetY() {
    return y_coordinate;
}

int AreaCalculation::GetSize() {
    return size;
}

AreaCalculation::~AreaCalculation() {
    delete(x_coordinate);
    delete(y_coordinate);
}

int AreaCalculation::FindStart() {
    int start = 0;
    int min = x_coordinate[0];
    for (int i = 1; i < size; i++) {
        if (x_coordinate[i] < min) {
            start = i;
            min = x_coordinate[i];
        }
    }
    return start;
}

int AreaCalculation::FindEnd() {
    int end = 0;
    int max = x_coordinate[0];
    for (int i = 1; i < size; i++) {
        if (x_coordinate[i] > max) {
            end = i;
            max = x_coordinate[i];
        }
    }
    return end;
}

void AreaCalculation::Transposition() {
    first = FindStart();
    last = FindEnd();
    if (x_coordinate[first] < 0) {
        double x_shift = fabs(x_coordinate[first]);
        for (int i = 0; i < size; i++) {
            x_coordinate[i] += x_shift;
        }
    }
    double y_min = y_coordinate[0];
    for (int i = 1; i < size; i++) {
        if (y_coordinate[i] < y_min) {
            y_min = y_coordinate[i];
        }
    }
    if (y_min < 0) {
        double y_shift = fabs(y_min);
        for (int i = 0; i < size; i++) {
            y_coordinate[i] += y_shift;
        }
    }
}
double AreaCalculation::AreaTrapetion(double _first_x,
double _second_x, double _first_y, double _second_y) {
    return (_first_y + _second_y)*(fabs(_first_x - _second_x)/2);
}
