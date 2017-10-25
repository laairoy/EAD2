# Add a vertical dotted line at x=0 to show centre (mean) of distribution.
set xzeroaxis
set grid

set style data histogram
set boxwidth 0.1
set style fill solid
#set xrange [0:*]
#set yrange [0:*]
set ylabel "" offset 2.5,0
#set xtic rotate by 90
set bmargin 2
#set xtics offset 0.5,-6.5
set xtics font ", 10"
set border 4

bin_width = 0.1;
bin_number(x) = floor(x/bin_width)

rounded(x) = bin_width * ( bin_number(x) + 0.5 )

set terminal 'png' size 800,600
set output 'healpMd.png'

plot 'healpMd.csv' using (rounded($1)):(1) smooth frequency with boxes title ""

set terminal 'png' size 800,600
set output 'healpMm.png'

plot 'healpMm.csv' using (rounded($1)):(1) smooth frequency with boxes title ""

set terminal 'png' size 800,600
set output 'heaqpMd.png'

plot 'heaqpMd.csv' using (rounded($1)):(1) smooth frequency with boxes title ""

set terminal 'png' size 800,600
set output 'heapMy.png'

plot 'heapMy.csv' using (rounded($1)):(1) smooth frequency with boxes title ""
