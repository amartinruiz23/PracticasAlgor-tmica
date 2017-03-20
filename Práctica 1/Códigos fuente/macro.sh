#!/bin/csh -vx
#echo "" >> salida.dat
@ i = 0
while ( $i <= 50000 )
./heapsort $i >> heapsort_OPTIMIZADO.dat
@ i += 1000
end
