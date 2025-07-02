#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>

class Motor {
private:
public:
    // Adicionado valor de RPM maximo, TODO: fazer isso dinamico
    static const int rpm_min = 0;
    static const int rpm_max = 10000;
    int rpms_int;
    void ligar();
    void desligar();
    bool aumentarRpm(int rpm_int);
    bool diminuirRpm(int rpm_int);
};

class Carro {
private:
    bool motorLigado_b = false;
    int rpmAtual_int = 0;
    std::vector<int> registrosRpm_int;

public:
    void ligarCarro();
    void desligarCarro();
    void aumentarRpmCarro(int rpm_int);
    void diminuirRpmCarro(int rpm_int);
    void exibirRegistros();
};

#endif
