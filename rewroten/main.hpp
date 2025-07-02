#ifndef REWRITE_H
#define REWRITE_H
#include <vector>

class Motor {
public:
    static const int RPM_MAX = 10000;
    static const int RPM_MIN = 0;


    int getRpm();
    bool setRpm(int pRpm);
    bool ligar();
    bool desligar();

    bool getLigado();
private:
    int rpm = 0;
    bool ligado = false;
};


class Carro {
public:
    bool ligar();
    bool desligar();
    bool aumentarRpm(int rpm_qtd);
    bool diminuirRpm(int rpm_qtd);
    void exibirRegistros();


private:
    Motor motor;
    std::vector<int> registrosRpm;
};

#endif // REWRITE_H
