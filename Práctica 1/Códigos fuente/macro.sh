#!/bin/csh -vx
#echo "" >> salida.dat
@ i = 0
while ( $i <= 50000 )
./burbuja $i >> burbuja_comparable.dat

@ i += 1000
end

@ i = 0
while ( $i <= 50000 )
./heapsort $i >> heapsort_comparable.dat

@ i += 1000
end

@ i = 0
while ( $i <= 50000 )
./insercion $i >> insercion_comparable.dat

@ i += 1000
end

@ i = 0
while ( $i <= 50000 )
./mergesort $i >> mergesort_comparable.dat

@ i += 1000
end

@ i = 0
while ( $i <= 50000 )
./seleccion $i >> seleccion_comparable.dat

@ i += 1000
end

@ i = 0
while ( $i <= 50000 )
./quicksort $i >> quicksort_comparable.dat

@ i += 1000
end
