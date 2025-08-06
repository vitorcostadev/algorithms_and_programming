Algoritmo "EXM1 - Questão 02"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Cálculo bancário
// Autor(a)    : Vitor Kawa P. Da Costa
// Data atual  : 07/04/2025
Var
numero_conta: inteiro
deposito, retirada, conta, valor_da_operation: real
tipo_de_operation: caractere
controlador: caractere

Inicio
controlador <- "S"

escreva("Primeiramente, informe o número da sua conta: ")
leia(numero_conta)
escreval("Agora, informe o saldo atual da sua conta: ")
leia(conta)

enquanto controlador <> "N" faca // Mais prático... , m
   escreval("Agora, informe o tipo da operação -> 'R' para retirada e 'D' para depósito: ")
   leia(tipo_de_operation)

   tipo_de_operation <- maiusc(tipo_de_operation)
   escolha (tipo_de_operation)

           caso "R"
                escreval()
                escreval("Ok, você quer fazer uma retirada, então informe o valor a ser retirado: ")
                leia(retirada)

                conta <- conta - retirada
                escreval("Conta N° ", numero_conta, ", você retirou ", retirada, " reais de sua conta.")
                escreval("Atualmente, você possui cerca de ", conta, " reais em sua conta.")

                se (conta < 0) entao
                   escreval("Você estourou sua conta.")
                fimse
           caso "D"
                escreval()
                escreval("Ok, então você quer fazer um deposito, então informe o valor a ser depositado: ")
                leia(deposito)

                conta <- conta + deposito
                escreval("Conta N° ", numero_conta, ", você depositou ", deposito, " reais em sua conta.")
                escreval("Seu saldo atual é de cerca de ", conta, " reais.")
           outrocaso
                    escreval("Opção inválida, tente novamente.")

   fimescolha

   escreval("Você deseja continuar nessa operação? S/N ")
   leia(controlador)
   
   controlador <- maiusc(controlador)
fimenquanto

Fimalgoritmo