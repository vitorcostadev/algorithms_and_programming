Algoritmo "EXM1 - Questão 07"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Definir aposentadoria de um CLT baseado na qty de anos servidos
// Autor(a)    : Vitor Kawã P. Da Costa
// Data atual  : 08/04/2025
Var
sexo: caractere
idade, anos_trabalhados: inteiro


Inicio
escreval(">>> Para definirmos sua aposentadoria, primeiramente informe a sua idade: ")
leia(idade)
escreval(">>> Agora, informe seu sexo [M] para masculino e [F] para feminimo.")
leia(sexo)
escreval(">>> Há quantos anos você trabalha? ")
leia(anos_trabalhados)

sexo <- maiusc(sexo)

escolha (sexo)
        caso "M"
             se ((idade >= 65) e (anos_trabalhados >= 30)) entao
                escreval("Baseado na prescrição de aposentadoria para pessoas do sexo Masculino,")
                escreval("você está apto à se aposentar!")
             senao
                  escreval("Sinto muito, mas você não está apto a se aposentar ainda.")
             fimse
        caso "F"
             se ((idade >= 60) e (anos_trabalhados >= 25)) entao
                escreval("Baseado na pescrição de aposentadoria para pessoas do sexo Feminino,")
                escreval("você está apto à se aposentar!")
             senao
                  escreval("Sinto muito, mas você não está apto a se aposentar no momento.")
             fimse
        outrocaso
                 escreval("Opção inválida, tente novamente.")
fimescolha


Fimalgoritmo