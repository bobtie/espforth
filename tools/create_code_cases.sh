grep 'as_.*,$' espforth_i.c  | sed 's/as_\(.*\),/case as_\1: return "\1";/' > /tmp/f.c
