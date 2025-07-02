#include "main.hpp"
#include <iostream>

bool Motor::desligar()
{
    if (ligado != true) {
        std::cout << "Carro já está desligado. Não é possivel desligar\n";
        return false;
    }
    std::cout << "Carro Desligado!\n";
    ligado = false;
    return true;
}

bool Motor::ligar()
{
    if (ligado != false) {
        std::cout << "Carro já está ligado. Não é possivel ligar\n";
        return false;
    }
    std::cout << "Carro Ligado!\n";
    ligado = true;
    return true;
}

bool Motor::getLigado() { return ligado; }

int Motor::getRpm() { return rpm; }

bool Motor::setRpm(int pRpm)
{
    if (pRpm < Motor::RPM_MIN || pRpm > Motor::RPM_MAX) {
        std::cout << "Não é possivel alterar para o RPM desejado " << pRpm << '\n';
        return false;
    }
    std::cout << "Alterando RPM para " << pRpm << '\n';
    rpm = pRpm;
    return true;
}

bool Carro::ligar() { return motor.ligar(); }
bool Carro::desligar() { return motor.desligar(); }
bool Carro::aumentarRpm(int rpm)
{
    if (motor.getLigado() != true) {
        std::cout << "É preciso estar com o carro ligado para alterar o RPM\n";
        return false;
    }

    return motor.setRpm(motor.getRpm() + rpm);
}
bool Carro::diminuirRpm(int rpm)
{

    if (motor.getLigado() != true) {
        std::cout << "É preciso estar com o carro ligado para alterar o RPM\n";
        return false;
    }

    return motor.setRpm(motor.getRpm() - rpm);
}

void Carro::exibirRegistros()
{
    for (size_t i = 0; i < registrosRpm.size(); i++) {
        std::cout << "Registro " << i + 1 << ": " << registrosRpm[i]
                  << " RPM\n";
    }
}

int main()
{
    Carro meuCarro;

    meuCarro.ligar();

    meuCarro.aumentarRpm(12000);
    meuCarro.diminuirRpm(13000);
    meuCarro.aumentarRpm(10000);
    meuCarro.diminuirRpm(2000);
    meuCarro.diminuirRpm(4000);
    meuCarro.aumentarRpm(8000);
    meuCarro.diminuirRpm(4000);

    meuCarro.desligar();
    meuCarro.exibirRegistros();

    return 0;
}
