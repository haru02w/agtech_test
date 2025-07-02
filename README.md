# Observações:
 - O codigo corrigido está na pasta `fixed`. Considere-o para avaliação
 - Tambem refiz o codigo usando algumas praticas mais recomendadas do que a estrutura de codigo proposta na pasta `rewrite`.

## Observações extras:
1. O `using namespace std;` não é recomendado pois pode conflitar com o namespace padrão utilizado pelo projeto. Não é um erro, mas uma má pratica.
2. Tem uma instancia da classe `Motor` que é global e alterada pelo carro. Não é uma boa prática usar instancias em escopo global
3. Eu alteraria a logica de todas as funções considerando que elas possam falhar e retornar codigo de erros, já que não tem como saber se as operações deram certo ou não pela execução das funções como foram propostas.

