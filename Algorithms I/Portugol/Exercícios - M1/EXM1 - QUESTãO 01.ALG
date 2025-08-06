Algoritmo "EXM1 - Questão 01"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calcular valores baseado em descontos (%)
// Autor(a)    : Vitor Kawã P. Da Costa
// Data atual  : 07/04/2025

// Colchonete = 10% de desconto
// Bandagens = 20% de desconto
// Boné de aba curta = 30% de desconto
//
// Os valores de cada objeto será informado pelo usuário no console,
// o objetivo deste algoritimo é calcular o valor baseado no desconto e na qty de
// cada objeto.
Var

bone_value, colchonete_value, bandagens_value, valor_final: real
bone_quantity, colchonete_quantity, bandagens_quantity: inteiro
bone_value_with_desc_and_qty, colchonete_value_with_desc_and_qty, bandagens_value_with_desc_and_qty: real
name: caractere
Inicio

// Obtendo os dados da compra e o nome do cliente.
escreval(">>> Por favor, informe seu nome, os valores e quantidades dos três itens que serão pedidos a seguir.")

escreva("Informe seu nome: ")
leia(name)
escreva(">>> Quantos bonés você comprou? ")
leia(bone_quantity)

se (bone_quantity <= 0) entao // Usuário bonzinho!
   escreval("Ok, sem bonés entao, prossiga.")
senao
     escreva(">>> Informe o valor do boné de aba curta: ")
     leia(bone_value)
fimse

escreva(">>> Quantos colchonetes você comprou? ")
leia(colchonete_quantity)

se (colchonete_quantity <= 0) entao
   escreval("Não comprou nenhum colchonete, ok, prossegue aí vai... :(")
senao
     escreva(">>> Informe o valor dos colchonetes: ")
     leia(colchonete_value)
fimse
escreva(">>> Quantas bandagens você comprou? ")
leia(bandagens_quantity)

se (bandagens_quantity <= 0) entao
   escreval("Nossa... nem bandagens você quer? tudo bem, prossegue ai.")
senao
     escreva(">>> E por fim, informe o valor das bandagens: ")
     leia(bandagens_value)
fimse

escreval() // Pular linha
// ===================================== || =================================

// Realizando os calculos

bone_value_with_desc_and_qty <- bone_quantity * (bone_value - (bone_value * 0.3)) // 0.3 = 30%
colchonete_value_with_desc_and_qty <- colchonete_quantity * (colchonete_value - (colchonete_value * 0.1)) // 0.1 = 10%
bandagens_value_with_desc_and_qty <- bandagens_quantity * (bandagens_value - (bandagens_value * 0.2)) // 0.2 = 20%

valor_final <- bone_value_with_desc_and_qty + colchonete_value_with_desc_and_qty + bandagens_value_with_desc_and_qty

// Imprimindo no console + checando

escreval("Sr(a) ", name, ", os itens que o(a) senhor(a) comprou possuem descontos distintos, sendo eles: ")
escreval("Bandagens possuem 20% de desconto.")
escreval("Colchonetes possuem 10% de desconto.")
escreval("Boné de aba curta possuem 30% de desconto.")

escreval() // again...

escreval("A sua compra, ao todo com o desconto aplicado ficou cerca de ", valor_final, " reais.")
se (bandagens_quantity > 0) entao
   escreval("As bandagens saíram de ", bandagens_quantity * bandagens_value, " reais, para ", bandagens_value_with_desc_and_qty, " reais.")
senao
     escreval("Você não comprou bandagens.")
fimse

se (colchonete_quantity > 0) entao
   escreval("Os colchonetes saíram de ", colchonete_quantity * colchonete_value, " reais, para ", colchonete_value_with_desc_and_qty, " reais.")
senao
     escreval("Você não comprou colchonetes.")
fimse

se (bone_quantity > 0) entao
   escreval("Os bonés de abas curtas saíram de ", bone_quantity * bone_value, " reais, para ", bone_value_with_desc_and_qty, " reais.")
senao
     escreval("Você não comprou bonés.")
fimse
Fimalgoritmo