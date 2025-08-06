Algoritmo "EXM1 - Questão 03"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calcúlo de média de notas
// Autor(a)    : Vitor K. Pedrosa da Costa
// Data atual  : 07/04/2025
Var
nota1, nota2, nota3, media: real
opcao: inteiro
peso1, peso2, peso3: inteiro

Inicio
escreval("Vamos calcular a média de três notas, mas você vai escolher a o tipo da média.")
escreval("[1] : Média Ponderada (terá que informar os pesos)")
escreval("[2] : Média Aritimética (tradicional)")
escreva("Faça sua escolha: ")
leia(opcao)

escreval(">>> Informe as três notas, por gentileza: ")
leia(nota1, nota2, nota3)

escolha (opcao)

        caso 1

             escreval("Você escolheu 'Média Ponderada'")
             
             escreval(">>> Agora, informe os pesos de cada nota: ")
             leia(peso1, peso2, peso3)
             
             media <- (nota1*peso1 + nota2*peso2 + nota3*peso3) / (peso1 + peso2 + peso3):8:2

             escreval("A sua média final é de: ", media, "!")
             se (media >= 7) entao
                escreval("Você está aprovado(a).")
             senao
                  escreval("Você está reprovado(a)!")
             fimse
        caso 2
             escreval("Você escolheu 'Média Aritimética'")
             
             media <- (nota1 + nota2 + nota3) / 3:8:2
             escreval("A sua média final é de ", media, "!")
             
             se (media >= 7) entao
                escreval("Você está aprovado(a)!")
             senao
                  escreval("Você está reprovado(a)!")
             fimse
fimescolha



Fimalgoritmo