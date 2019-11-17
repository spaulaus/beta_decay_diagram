reset
unset key
set xtics nomirror
set ytics nomirror
set format " "
file='test.dat'

set output "pic/graph.eps"
set terminal postscript eps color enhanced solid "Helvetica,24"
#set terminal wxt enhanced color 

set multiplot layout 1,3
#The Plot for the S_beta
set xrange [0:11]
set origin 0,0
set size 0.4,1.0
plot file u 2:1 w lines lw 4 lc rgb prim3

#The Fermi Integral Plot
set auto x
set origin 0.315,0
set size 0.4,1.0
plot file u 3:1 w lines lw 4 lc rgb prim3

#The Intensity Plot
set origin 0.63,0
set size 0.4,1.0
plot file u ($2*$3):1 w lines lw 4 lc rgb prim3
unset multiplot