\ i2c interface for PCF8574

HEX
\ I2C address for the PCF8574
40 CONSTANT PCF8574ADDR
DECIMAL

: pcf-w ( n -- e ) \ Write byte n to PCF8574
    PCF8574ADDR i2c-m-write
    dup if ." I2C error:" . CR else drop then
;

: HELP
    ." PCF8574 I2C interface ver 1.0. Available words:" CR
    ." pcf-w ( n -- ) Write byte n to PCF8574" CR
;

HELP