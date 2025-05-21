\ a simple elevator for esp32

\ there are 4 buttons 0,1,2,3 and 4 leds 0,1,2,3
\ only the led corresponding to the floor the elevator is at is on
\ initially the elevator is at rest
\ when the elevator is a rest, 
\       if a button at a floor different than the one the elevator is at is pressed 
\                   the elevator move toward the selected floor (called target floor)
\ when a moving elevator reaches the target floor it stops


1 CONSTANT PININMODE
2 CONSTANT PINOUTMODE

VARIABLE BUTTONS 3 CELLS ALLOT
VARIABLE LEDS 3 CELLS ALLOT

VARIABLE ELEV-SIM-POSITION \ elevator simulator: cm from ground
VARIABLE ELEV-SIM-DIRECTION

2 CONSTANT ELEV-SIM-SPEED

300 CONSTANT ELEV-SIM-FLOOR-HEIGHT

ELEV-SIM-FLOOR-HEIGHT 3 * CONSTANT ELEV-SIM-CEIL

5 CONSTANT ELEV-SIM-SENSOR-RANGE

: ELEV-SIM-INIT
    0 ELEV-SIM-POSITION !
    0 ELEV-SIM-DIRECTION !
;

: ELEV-SIM-UP
    1 ELEV-SIM-DIRECTION !
;

: ELEV-SIM-DW
    -1 ELEV-SIM-DIRECTION !
;

: ELEV-SIM-STOP
    0 ELEV-SIM-DIRECTION !
;

: ELEV-SIM-STEP
    ELEV-SIM-POSITION @ ELEV-SIM-DIRECTION @ ELEV-SIM-SPEED * + 
    DUP 0 < IF ." elevator crashed at ground" CR BYE ELSE
    DUP ELEV-SIM-CEIL SWAP < IF ." elevator crashed at ceil" CR BYE ELSE
        ELEV-SIM-POSITION !
    THEN THEN
;


: ELEV-SIM-DUMP
    ." elevator position : " ELEV-SIM-POSITION @ . CR
    ." elevator direction: " ELEV-SIM-DIRECTION @ . CR
    ;

: ELEV-SIM-SENSOR ( n -- m )
    ELEV-SIM-POSITION @ ELEV-SIM-FLOOR-HEIGHT /MOD 
    SWAP
    ELEV-SIM-SENSOR-RANGE < IF = IF 1 ELSE 0 THEN ELSE DROP DROP 0 THEN
;

\ -- utils

variable RSTATE

: RAND ( -- n)
    RSTATE @ 1664525 * 1013904223 + 4294967296 MOD DUP RSTATE !
;

: NRAND ( n -- n1 )
    RAND SWAP MOD
;


: SWAP-R 
    R> R> R> SWAP >R >R >R
;

: << ( n1 n2 -- n3 ) \ left shift
    FOR AFT 2 * THEN NEXT
;


: .S 
    2 FOR ROT DUP . NEXT
;

: SHOW-PIN-NUMBERS ( -- )
\ display pin 
    0 >R 3 FOR ." button: " SWAP-R R@ . BUTTONS R@ cells + @ BL EMIT ." pin: " . CR R> 1 + >R SWAP-R NEXT R> DROP
    0 >R 3 FOR ." led   : " SWAP-R R@ . LEDS    R@ cells + @ BL EMIT ." pin: " . CR R> 1 + >R SWAP-R NEXT R> DROP
;

: .PINMODE ( n -- )
    DUP 1 = IF ." input" DROP ELSE 2 = IF ." output"  ELSE ." ERROR: unknown mode" ABORT THEN THEN
;

\ begin simulate gpio
\ : PINMODE ( n p -- )
\     SWAP
\     ." set mode " .PINMODE BL EMIT ." for pin " . CR
\ ;

\ : PINSET ( n p -- ) 
\     ." set pin " . BL EMIT ." to " . CR
\ ;

\ : PINGET ( n -- m )
\     ." get pin " . BL EMIT ." as " 1 dup . CR
\ ;
\ end of simulate gpio

: INIT-PIN-NUMBERS ( -- )
    13 BUTTONS 0 cells + !
    14 BUTTONS 1 cells + !
    27 BUTTONS 2 cells + !
    26 BUTTONS 3 cells + !

    2 LEDS 0 cells + !
    0 LEDS 1 cells + !
    4 LEDS 2 cells + !
    5 LEDS 3 cells + !
;

: PINMODE-4 ( mode addr -- )
        2DUP 0 cells + @ PINMODE
        2DUP 1 cells + @ PINMODE
        2DUP 2 cells + @ PINMODE
             3 cells + @ PINMODE
;

: INIT-MODES ( -- )
    PININMODE  BUTTONS PINMODE-4
    PINOUTMODE LEDS PINMODE-4
;

\ : ?ELEV-FLOOR ( n -- flag )
\     ELEV-POSITION 300 /MOD SWAP 0= IF 
\ ;

: SHOW-ELEV
    \ 3 FOR R@ ?ELEV-FLOOR IF 1 ELSE 0 THEN LEDS R@ CELLS + @ PINSET NEXT
;

: INIT ( -- ) \ initialize wires for buttons and leds
    INIT-PIN-NUMBERS
    SHOW-PIN-NUMBERS
    INIT-MODES
;

: MOVE-ELEV ( n -- )
  dup ." elev moving to floor:" . CR
\   ELEV-FLOOR ! SHOW-ELEV
;

: GET-BUTTON ( n - )
  CELLS BUTTONS + @ PINGET
;

: SCAN-BUTTONS
  0 3 FOR 2 * 1 R@ GET-BUTTON - +
  NEXT
;

: RUN 
    BEGIN SCAN-BUTTONS DUP
        1 = IF 3 MOVE-ELEV ELSE DUP
        2 = IF 2 MOVE-ELEV ELSE DUP
        4 = IF 1 MOVE-ELEV ELSE DUP
        8 = IF 0 MOVE-ELEV ELSE
        THEN THEN THEN THEN
    AGAIN
;


\ INIT

\ INIT CR SHOW-ELEV CR \ BYE

: ELEV-SCAN-SENSORS
    0 3 FOR 2 * R@ ELEV-SIM-SENSOR +
    NEXT
;

: SET-LED ( n1 n2 -- ) \ set led n2 to level n1
    LEDS SWAP CELLS + @ PINSET
;

: DRIVE-LEDS ( n -- ) \ set a led on/off depending on given bit mask
    3 FOR DUP 1 R@ << AND IF 1 ELSE 0 THEN R@ SET-LED NEXT DROP
;

: T-STEP
        ELEV-SIM-STEP ELEV-SIM-DUMP
        ." sensor readings:" ELEV-SCAN-SENSORS . CR
;

: T2
    ELEV-SIM-INIT
    ELEV-SIM-UP
;



: T ( m -- n )
    1 SWAP << >R \ save target floor
    T2
    1
    BEGIN
        DUP ." step:" . CR 1+
        T-STEP
        ELEV-SCAN-SENSORS R@ = 
    UNTIL
    R> DROP
;

: T1
    INIT
    BEGIN
        16 NRAND DRIVE-LEDS 100 MS 
    AGAIN
;

: T2 
    INIT
    BEGIN
        SCAN-BUTTONS DRIVE-LEDS
    AGAIN
;

: HELP
    ." use 'T' for testing." CR
;