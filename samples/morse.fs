\ connect pin 18 with speaker
880 18 TONE-INIT
VARIABLE DOT-TIME

\ duration of a symbol, i.e. the beep of a dot
100 DOT-TIME !

: TONE-ACTION
    \ TONE-STATE 
    ." l:" . SPACE
;

: TIME-ACTION
    \ MS
    ." p:" . SPACE
;

: DS \ dot space
    DOT-TIME @ TIME-ACTION
;

: LS \ letter space
    DS DS 
;

: WS \ word space
    DS DS DS DS
;

: DOT 
    1 TONE-ACTION DS 0 TONE-ACTION DS
;

: LINE 
    1 TONE-ACTION DS DS DS 0 TONE-ACTION DS
;

: SOS  DOT DOT DOT LS LINE LINE LINE LS DOT DOT DOT WS
;

: A DOT LINE LS ;
: B LINE DOT DOT DOT LS ;
: C LINE DOT LINE DOT LS ;
: D LINE DOT DOT LS ;
: E DOT LS ;
: F DOT DOT LINE DOT LS ;
: G LINE LINE DOT LS ;
: H DOT DOT DOT DOT LS ;
: I DOT DOT LS ;
: J DOT LINE LINE LINE LS ;
: K LINE DOT LINE LS ;
: L DOT LINE DOT DOT LS ;
: M LINE LINE LS ;
: N LINE DOT LS ;
: O LINE LINE LINE LS ;
: P DOT LINE LINE DOT LS ;
: Q LINE LINE DOT LINE LS ;
: R DOT LINE DOT LS ;
: S DOT DOT DOT LS ;
: T LINE LS ;
: U DOT DOT LINE LS ;
: V DOT DOT DOT LINE LS ;
: W DOT LINE LINE LS ;
: X LINE DOT DOT LINE LS ;
: Y LINE DOT LINE LINE LS ;
: Z LINE LINE DOT DOT LS ;

VARIABLE CODES  ' A , ' B , ' C , ' D , ' E , ' F , ' G , ' H , ' I , ' J , ' K , ' L , ' M , ' N , ' O , ' P , ' Q , ' R , ' S , ' T , ' U , ' V , ' W , ' X , ' Y , ' Z ,

: >MORSE ( n -- ) \ emit a character A-Z as morse code
    65 - 1+ CELLS CODES + @ EXECUTE
;

: ACCEPT-MORSE
    TIB 100 ACCEPT 1- DUP FOR DUP R@ - TIB + C@ DUP 32 = IF WS ELSE >upper >MORSE THEN NEXT DROP
;

: DEMO1
    ." the word roberto will be emitted after you have pressed a key" KEY DROP
    R O B E R T O
;

: DEMO2
    ." emit the alphabeth after you have pressed a key" KEY DROP
    24 FOR 24 R@ - >MORSE NEXT
;

: DEMO3
    BEGIN
    ." type a string, it will be emitted as morse: " 
    CR ACCEPT-MORSE CR
    AGAIN
;



: HELP
    CR CR ." morse example ver. 1.10" CR 
    ." try: DEMO1 DEMO2 or DEMO3" CR
;

HELP