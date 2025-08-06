Algoritmo "EXM1 - Questão 08"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calculo de produto baseado em desconto ou acrescimo.
// Autor(a)    : Vitor K. Pedrosa da Costa
// Data atual  : 08/04/2025
Var
preco: real
codigo: inteiro
desconto, juros: real


Inicio
escreval(">>> Informe o preço de etiqueta do produto: ")
leia(preco)
escreval()

escreval(">>> Como deseja pagar?")
escreval("[1] : Pagamento à vista no dinheiro ou cheque (10% de desconto!")
escreval("[2] : Pagamento à vista no cartão de crédito (15% de desconto!)")
escreval("[3] : Em 2x sem juros")
escreval("[4] : Em 2x com juros de 10%")
escreval()
escreva(">>> Faça sua escolha: ")
leia(codigo)

escolha (codigo)
        caso 1
             desconto <- preco - (preco * 0.1)
             escreval(">>> Você terá que pagar, ",desconto:8:2," reais pelo produto.")
             escreval("O preço inicialmente seria de, ",preco," reais, mas foi aplicado o desconto de 10%.")
        caso 2
             desconto <- preco - (preco * 0.15)
             escreval(">>> Você terá que pagar, ",desconto:8:2," reais pelo produto.")
             escreval("O preço inicialmente seria de, ",preco," reais, mas foi aplicado o desconto de 15%.")
        caso 3
        escreval(">>> Você terá que pagar, ",preco," reais pelo produto.")
             escreval("Nenhum desconto ou acréscimo foi aplicado.")
        caso 4
             juros <- preco + (preco * 0.1)
             escreval(">>> Você terá que pagar, ",juros:8:2," reais pelo produto.")
             escreval("O preço inicialmente seria de, ",preco," reais, mas foi aplicado um acréscimo de 10%.")
        outrocaso
                 escreval("Opção inválida, tente novamente.")
fimescolha

             


Fimalgoritmo