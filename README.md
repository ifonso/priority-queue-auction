# Leilão com Filas de Prioridade

A tua empresa tem a seu cargo um leilão de cromos raros. O leilão funciona do seguinte modo:
- A qualquer momento um comprador pode fazer uma oferta de compra, especificando o preço pelo qual quer comprar um cromo.
- A qualquer momento um vendedor pode decidir vender o seu cromo, sendo que o irá vender à melhor oferta (a que paga mais).

Um exemplo de leilão seria o seguinte:
1. João faz uma oferta de 20€;
2. Ana faz uma oferta de 35€;
3. Raquel faz uma oferta de 15€;
4. Alguém decide vender. Face às 3 ofertas na mesa (João, Ana e Raquel), vendo à Ana por 35€, que recebe o cromo e por isso deixa de estar interessada em comprar mais cromos;
5. Pedro faz uma oferta de 45€;
6. Alguém decide vender. Face às 3 ofertas na mesa (João, Raquel e Pedro), vende ao Pedro por 45€;
7. Alguém decide vender. Face às 2 ofertas na mesa (João e Raquel), vende ao João por 20€.

Dados os eventos de um leilão a tua tarefa é descobrir a quem é vendido cada cromo.

## Detalhes

**Input**: A primeira linha contém `N`, a quantidade de eventos `(1<N<10_000)`. Seguem-se `N` cada uma delas contendo apenas a palavra `VENDA` se for alguém que decidiu vender, ou `OFERTA` nome preço se for uma oferta de compra (o nome é uma string sem espaços e o preço um número inteiro menor que 1 milhão).

> Espreita o exemplo de input para perceberes melhor (corresponde ao exemplo do enunciado).

**Output**: O output deve ser constituído por tantas linhas quantas as ocorrências da palavra VENDA no input. Em cada uma dessas linhas, que vêm pela ordem das vendas, deve vir o preço e o nome do comprador da respectiva venda, separados por um espaço.

> É garantido que quando alguém quer vender existe sempre pelo menos uma oferta e que não existem empates (há sempre alguém com um preço máximo).

## Exemplo
Exemplo de input:
```
7
OFERTA Joao 20
OFERTA Ana 35
OFERTA Raquel 15
VENDA
OFERTA Pedro 45
VENDA
VENDA
```

Exemplo de output:
```
35 Ana
45 Pedro
20 Joao
```