: HELLO ." Hello Forth user: file example 3" ;
CR HELLO CR CR 

: 0= INVERSE ;
: FN $" /spiflash/prova.fs" ;
: W $" hello world!!!\n" ;
VARIABLE FD
VARIABLE BUF 100 ALLOT

: CLOSE-FILE-MSG  ( n -- )
		close-file 0= IF
		." close done!!!" CR
		ELSE
		." close error:" . CR
		THEN ;

: TEST-CREATE-FILE FN count w/o create-file 0= IF 
	>R W count R@ write-file 0= IF
		." write done!!!" CR
		ELSE
		." write error:" . CR
		THEN
		R> CLOSE-FILE-MSG
	ELSE
	." open error:" . CR
	THEN ;

: TEST-READ-FILE FN count r/o open-file 0= IF
	." file opened!" CR
	>R BUF 10 R@ read-file 0= IF
			." buffer read, len: " DUP . CR
			." content:" BUF 10 TYPE CR
		ELSE
			." cannot read buffer, reason:" . CR
		THEN
		R> CLOSE-FILE-MSG 
	ELSE
	." cannot open file, error:" . CR
	THEN
	 ;

