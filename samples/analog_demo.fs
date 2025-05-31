: ADC-DEMO
    6 ADC-INIT \ pin 38
    BEGIN
        6 ADC-READ ." read:" . CR
        250 MS
    AGAIN
;

: HELP
    ." adc demo ver 1.0 - type ADC-DEMO" CR
;

HELP