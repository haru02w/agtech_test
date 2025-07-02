#include "main.hpp"
#include <iostream>

void Motor::ligar() { std::cout << "Motor Ligado!" << std::endl; }

void Motor::desligar() { std::cout << "Motor desligado!" << std::endl; }

// Coloquei retorno de booleano pra saber quando a operação falhou ou não
bool Motor::aumentarRpm(int rpm_int)
{
    // Retira numeros hard-coded, propicio a erros. Coloca numero estatico constante.
    if (rpm_int < Motor::rpm_min) {
        std::cout << "RPM nao pode ser negativo!" << std::endl;
        return false;
    }
    if (rpm_int > Motor::rpm_max) {
        std::cout << "RPM máximo atingido!" << std::endl;
        return false;
    }
    std::cout << "Aumentando RPM para " << rpm_int << std::endl;
    // Altera o RPM do motor. Não utilizado no codigo original...
    rpms_int = rpm_int;
    return true;
}

// Coloquei retorno de booleano pra saber quando a operação falhou ou não
bool Motor::diminuirRpm(int rpm_int)
{
    // if (rpm_int < -1000) {
    if (rpm_int < Motor::rpm_min) { // Numero hard-coded. Propicio a erros.
        std::cout << "RPM nao pode ser negativo!" << std::endl;
        // while (1) { }; // Isso trava a execução do programa. Isso nunca pode
        // acontecer!
        return false;
    }
    if (rpm_int > Motor::rpm_max) {
        // } else if (rpm_int > 100000) { // Numero hard-coded. Propicio a
        // erros. Não é 100000, é 10000
        std::cout << "RPM nao pode ser maior que 10000!" << std::endl;
        return false;
    }
    std::cout << "Diminuindo RPM para " << rpm_int << std::endl;
    rpms_int = rpm_int;
    return true;
}

Motor motor_class; // Essa instancia classe não deveria ser global, mas ok.
                   // Dá entender o uso devido a pequena escala do teste

void Carro::ligarCarro()
{
    // Adicionado a verificação se o carro já está ligado
    if (motorLigado_b == true) {
        std::cout << "Carro já está ligado!" << std::endl;
        return;
    }

    // Eu adicionaria algum retorno para indicar falha ou sucesso da função, mas não é necessario nesse caso.
    motor_class.ligar();
    motorLigado_b = true;
};

void Carro::desligarCarro()
{
    if (motorLigado_b != true) {
        std::cout << "Carro já está desligado!" << std::endl;
        return;
    }
    // Eu adicionaria algum retorno para indicar falha ou sucesso da função, mas não é necessario nesse caso.
    motor_class.desligar();
    motorLigado_b = false;
};

void Carro::aumentarRpmCarro(int rpm_int)
{
    if (!motorLigado_b) {
        std::cout << "O motor precisa estar ligado!" << std::endl;
        return;
    }

    // somente se o motor conseguir aumentar o RPM, o RPM atual é alterado e
    // entra pro registro.
    if (motor_class.aumentarRpm(rpmAtual_int + rpm_int) == true) {

        rpmAtual_int += rpm_int;
        registrosRpm_int.push_back(rpmAtual_int);
    }
};

void Carro::diminuirRpmCarro(int rpm_int)
{
    if (!motorLigado_b) {
        std::cout << "O motor precisa estar ligado!" << std::endl;
    }

    // somente se o motor conseguir diminuir o RPM, o RPM atual é alterado e
    // entra pro registro.
    if (motor_class.diminuirRpm(rpmAtual_int - rpm_int) == true) {
        rpmAtual_int -= rpm_int;
        registrosRpm_int.push_back(rpmAtual_int);
    }
};

void Carro::exibirRegistros()
{
    // Seria mais interessante utilizar um 'foreach' aqui pra não correr o risco
    // em um possivel ambiente multithread.
    for (int i = 0; i < registrosRpm_int.size(); i++) {
        // if (i < 4) { // Não tem porque limitar os registros demonstrados...
        std::cout << "Registro " << i + 1 << ": " << registrosRpm_int[i]
                  << " RPM" << std::endl;
        // }
    }
};

int main()
{
    Carro meuCarro;

    meuCarro.ligarCarro();

    meuCarro.aumentarRpmCarro(12000);
    meuCarro.diminuirRpmCarro(13000);
    meuCarro.aumentarRpmCarro(10000);
    meuCarro.diminuirRpmCarro(2000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(1000);
    meuCarro.diminuirRpmCarro(4000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(4000);

    meuCarro.desligarCarro();
    meuCarro.exibirRegistros();

    return 0;
}
