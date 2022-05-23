#ifndef VECTOR_H
#define VECTOR_H

#include <QVector>

template <class T> class Vector : public QVector<T> {
private:
    int size() {
        return 0;
    }

public:
    T at(int i) {
        return QVector::at(i-1);
    }

    float getPromedio() {
        if(typeid(T) == typeid(int) || typeid(T) == typeid(float)) {
            int prom;
            prom += T;
            return prom;
        }

        return -1;
    }
};


#endif // VECTOR_H
