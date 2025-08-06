Algoritmo "EX05"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Vitor Costa
// Data atual  : 24/03/2025
Var
// Seção de Declarações das variáveis 

option,n1,n2,n3: inteiro
Inicio
//5. Escreva um algoritmo que leia 4 números inteiros (opção, n1, n2, n3) e escreve-os da seguinte maneira:
 //se opção = 1 escreva o número n1
 //se opção = 2 escreva o número n2
 //se opção = 3 escreva o número n3
 //se opção for outro valor qualquer escreva opção inválida
 
 escreval(">>> Digite uma opção [1,2,3...]: ")
 leia(option)
 escreval(">>>> Agora, digite três números aleatórios: ")
 leia(n1,n2,n3)
 
 escolha (option)

         caso 1
              escreval("Você recebeu o valor: ", n1)
         caso 2
              escreval("Você recebeu o valor: ", n2)
         caso 3
              escreval("Você recebeu o valor: ", n3)
         outrocaso
                  escreval("Opção inválida!")
         fimescolha


Fimalgoritmo