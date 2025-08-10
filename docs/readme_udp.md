# A Forth set of words to use UDP

## UDP Networking Words

- udp-init         ( -- )            : Initialize UDP subsystem
- udp-open         ( n -- h )        : Open a UDP socket on local port n, returns handle h
- udp-close        ( h -- )          : Close a UDP socket handle h
- udp-send         ( addr len -- )   : Send data at addr/len via UDP
- udp-recv         ( -- addr len )   : Receive data, returns address and length
- udp-set-remote   ( h addr port -- ): Set remote IP (addr) and port for handle h
- udp-get-remote   ( h -- addr port ): Get remote IP and port for handle h
- udp-bind         ( h port -- )     : Bind socket handle h to local port
- udp-listen       ( h -- )          : Listen for incoming UDP packets on handle h
- udp-error        ( -- n )          : Get last UDP error code

## Example: Sending and Receiving UDP Packets

```
udp-init                \ Initialize UDP subsystem
12345 udp-open          \ Open UDP socket on local port 12345
"192.168.1.100" 5000 udp-set-remote  \ Set remote IP and port
s" Hello, UDP!" udp-send \ Send string to remote
udp-recv                \ Receive data ( -- addr len )
.                       \ Print received data
udp-close               \ Close UDP socket
```




