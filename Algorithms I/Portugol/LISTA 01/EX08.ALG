Algoritmo "EX08"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calcular a distância entre dois pontos
// Autor(a)    : Vitor Costa
// Data atual  : 15/03/2025
Var
// Seção de Declarações das variáveis 
x1,y1,x2,y2,d: real

Inicio
// Calcular distância entre dois pontos P¹(x1, y1) P²(x2, y2)
escreval(">>> Informe o valor do ponto P¹(x¹, ...): ")
leia(x1)
escreval(">>> Informe o valor do ponto P¹(..., y¹): ")
leia(y1)
escreval(">>> Agora, informe o  valor do ponto P²(x², ...): ")
leia(x2)
escreval(">>> Por fim, informe o valor do ponto P²(..., y²): ")
leia(y2)

d <- raizq( (x2 - x1)^2 + (y2 - y1)^2 )
escreval("A distância entre os dois pontos é de: ", d)


Fimalgoritmo