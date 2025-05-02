: 0= INVERSE ;
: FN $" prova.fs" ;
: W $" hello world!!!\n" ;
VARIABLE FD

: RUN FN count w/o create-file 0= IF 
	>R W count R@ write-file 0= IF
		." write done!!!" CR
		ELSE
		." write error:" . CR
		THEN
		R> close-file 0= IF
		." close done!!!" CR
		ELSE
		." close error:" . CR
		THEN
	ELSE
	." open error:" . CR
	THEN ;
RUN
