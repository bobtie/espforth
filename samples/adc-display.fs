    \ connect 7seg's clk/dio with esp32's SCL/SDA
    \ i2c_master_init();

    \ // Turn display on, brightness max
    \ i2c_write(0x48, 0xF1);

    \ // Write numbers to digits
    \ i2c_write(0x68, 0x3F); // "0"
    \ i2c_write(0x6A, 0x06); // "1"
    \ i2c_write(0x6C, 0x5B); // "2"
    \ i2c_write(0x6E, 0x4F); // "3"


\   --0--       Segment A (bit 0)
\  |     |
\  5     1      Segment F (bit 5), Segment B (bit 1)
\  |     |
\   --6--       Segment G (bit 6)
\  |     |
\  4     2      Segment E (bit 4), Segment C (bit 2)
\  |     |
\   --3--   •7  Segment D (bit 3), Dot/Decimal (bit 7)


i2c-m-init

hex

68 constant 7s-left
variable 7s-map 3F , 06 , 5B , 4F , 66 , 6D , 7D , 07 , 7F , 6F ,

: 7s-turnon
    11 48 i2c-m-write
;

decimal

: 7s-map-number
    1 + cells 7s-map + @
;

: 7s-digit ( n d - ) \ display number n on digit d (right to left)
    \ ." called:" dup . swap dup . swap CR
    3 swap - 2 * 7s-left + swap 7s-map-number swap i2c-m-write 
    drop \ forget error code
;

: POW ( n1 n2 - n3 ) \ n3 = n1^n2 
    1 SWAP FOR AFT OVER * THEN NEXT SWAP DROP
;

: 7s-number ( n -- ) \ display a number on the 7-segs display
    3 FOR 
        10 R@ POW /MOD R@ 7s-digit \ 1000 ms
    NEXT 
    drop
;

: DEMO
    6 ADC-INIT \ pin 38
    BEGIN
        6 ADC-READ 7s-number
        100 MS
    AGAIN