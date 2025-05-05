\ test of 'load' function 

\ define a word P for the string defining the word T
: P $" : T 9999 ;" ;

\ load the content of P
P count load

\ call T
T .
