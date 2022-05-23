#ifndef ORDENADOR_H
#define ORDENADOR_H

template <class T> class Ordenador  {
public:
    void burbuja(T * v, int n) {
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (v[j] > v[j+1]) {
                    T aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }

    void insercion(T * v, int n) {
        for (int j = 1; j < n; j++) {
            int y = v[j];
            int k;
            for(k = j-1; k >= 0 && y < v[k]; k--) {
                v[k+1] = v[k];
            }
            v[k+1] = y;
        }
    }

    void seleccion(T * v, int n) {
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(v[i] > v[j]) {
                    T aux = v[j];
                    v[j] = v[i];
                    v[i] = aux;
                }
            }
        }
    }
};

#endif // ORDENADOR_H
