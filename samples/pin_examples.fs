 VARIABLE TIME

 : INIT
    500 TIME !
    2 18 PINMODE
 ;
 
 : RUN
    BEGIN 1 18 PINSET TIME @ MS 0 18 PINSET TIME @ MS AGAIN 
;

: HELP
    ." simple demo for gpio ver 1.0. attach a led to pin 18. type: INIT RUN" CR
;