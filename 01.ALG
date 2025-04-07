Algoritmo "01"

Var
A, B, S:real

funcao f(x,y:real) : real
inicio
      retorne ((2*x) + 3*(y^2))
fimfuncao

Inicio
      escreval ("Digite dois numeros:")
      Leia (A, B)
      S <- f(A,B)
      escreval ("O resoltado foi: ", S)
Fimalgoritmo