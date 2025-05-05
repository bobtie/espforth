: HELLO CR CR ." hello user!!! ver. 1.0" CR CR ;

: n,   compile dolit , ;

: [']   ' n, ; immediate

: SEE
   ' BEGIN CELL+ DUP @ DUP IF >NAME THEN ?DUP
   IF SPACE .ID ELSE DUP @ U. THEN DUP @ ['] EXIT =
   UNTIL DROP ;

: TEST-UNTIL >R 0 BEGIN DUP . 1+ DUP R@ = UNTIL DROP R> DROP ;

: TEST-FOR 10 FOR R@ . NEXT ;

: TEST-FOR-AFT 10 FOR R@ . NEXT ;

HELLO

