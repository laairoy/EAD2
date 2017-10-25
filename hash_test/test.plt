set title "" font ", 24"
set datafile separator ","
set grid

set style data histogram
set boxwidth 2
set style fill solid

set ylabel "" offset 2.5,0
#set xtic rotate by 90
set bmargin 2
#set xtics offset 0.5,-6.5
set xtics font ", 10"
set border 10

set terminal 'png' size 800,600
set output 'healpMd.png'

plot 'healpMd.csv' using 2:xtic(1) title ""

set terminal 'png' size 800,600
set output 'healpMm.png'

plot 'healpMm.csv' using 2:xtic(1) title ""

set terminal 'png' size 800,600
set output 'heaqpMd.png'

plot 'heaqpMd.csv' using 2:xtic(1) title ""

set terminal 'png' size 800,600
set output 'heapMy.png'

plot 'heapMy.csv' using 2:xtic(1) title ""
