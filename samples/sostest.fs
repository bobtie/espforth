100 constant BEAT

: testinit 2 2 pinmode ;
: on 1 2 pinset ;
: off 0 2 pinset ;
: dot BEAT DUP on ms off ms ;
: dash on BEAT DUP 2 * ms off ms ;
: gap BEAT 2 * ms ;
: sos dot dot dot gap dash dash dash gap dot dot dot gap ;
: test testinit begin sos gap again ;
