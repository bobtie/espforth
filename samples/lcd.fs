\ initialization for LCD display using I2C
\ This code is for a 4-bit LCD display controlled via I2C.
\ The example was created by ChatGPT

\ lcd_send_nibble(0x30); vTaskDelay(5 / portTICK_PERIOD_MS);
\ lcd_send_nibble(0x30); vTaskDelay(1 / portTICK_PERIOD_MS);
\ lcd_send_nibble(0x30); vTaskDelay(1 / portTICK_PERIOD_MS);
\ lcd_send_nibble(0x20); // Set to 4-bit mode

\ lcd_send_cmd(0x28); // Function set: 4-bit, 2 line, 5x8 dots
\ lcd_send_cmd(0x08); // Display off
\ lcd_send_cmd(0x01); // Clear display
\ vTaskDelay(2 / portTICK_PERIOD_MS);
\ lcd_send_cmd(0x06); // Entry mode set: increment cursor
\ lcd_send_cmd(0x0C); // Display ON, Cursor OFF, Blink OFF



\ Pin   Signal
\ -----------------
\ P0    RS 1=DATA, 0=COMMAND
\ P1    RW 1=READ, 0=WRITE
\ P2    CS enable (high to low transition)
\ P3    x
\ P4    D4
\ P5    D5
\ P6    D6
\ P7    D7

HEX
27 2 * CONSTANT LCDADDR

4 CONSTANT EN 


: i \ Initialize the I2C bus
    i2c-m-init
;


: s ( n -- e ) \ Send the byte n to the LCD display leaving 0 if no error occurred
    LCDADDR i2c-m-write
    then
;


: check-error ( n -- ) \ Check for I2C error
    if ." I2C error" CR else then
;

: se ( n -- r1 r2 ) \ send with enable pulse
    dup 
    EN or s check-error
    EN inverse and s check-error
;

: sb ( n rs -- ) \ send a command or data byte
    >R DUP F0 and R@ or se 
    0F and 10 ( hex ) * R> or se
;

: cmd ( n -- ) \ send a command
    0 sb
;

: data ( n -- ) \ send a data byte
    1 sb
;

: init
    i \ Initialize the I2C bus
    30 se
    30 se
    30 se
    20 se \ Set to 4-bit mode
    28 cmd \ Function set: 4-bit, 2 line, 5x8 dots
    08 cmd \ Display off
    01 cmd \ Clear display
    06 cmd \ Entry mode set: increment cursor
    0C cmd \ Display ON, Cursor OFF, Blink OFF
;

: roberto-reversed
    4F 54 52 45 42 4F 52  \ "OTREBOR"
;

: lcd-write ( c-addr u -- ) \ Write a string to the LCD
    dup 1 -
    FOR
        2dup R@ - + 1 - c@ data 
    NEXT
;

: message
    $" ciao bruno!" COUNT lcd-write
;

: roberto
     roberto-reversed 6 for data next
;

: HELP
." if hex is selected, you see FF in the stack" CR
;

FF HELP