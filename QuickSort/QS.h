//
// Created by Christian Bain on 2019-06-01.
//

#pragma once
#include "QSInterface.h"
#include <sstream>

class QS : public QSInterface {

public:
    QS();
    ~QS();                                                  // using destructor

     void sort(int left, int right);
     void sortAll();
     int medianOfThree(int left, int right);
     int partition(int left, int right, int pivotIndex);
     string getArray();
     int getSize();
     bool addToArray(int value);
     bool createArray(int size);
     void clear();
};
