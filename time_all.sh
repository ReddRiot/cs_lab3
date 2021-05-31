#!/bin/bash
cd ~/comb_sort
ml icc

icc CombSort.cpp -o none_$ind
qsub -N none_$ind -l nodes=1:ppn=1,walltime=04:00:00 -v executable=none_$ind measure_executable.sh

for i in {0..3}
do
	icc -O$i CombSort.cpp -o O$i,_$ind
	qsub -N O$i,_$ind -l nodes=1:ppn=1,walltime=04:00:00 -v executable=O$i,_$ind measure_executable.sh
done

extentions="sse2 sse3 ssse3 sse4.1 sse4.2 avx"
for ext in $extentions
do
	icc -x$ext CombSort.cpp -o fl_$ext,_$ind
	qsub -N $ext,_$ind -l nodes=1:ppn=1,walltime=04:00:00 -v executable=$ext,_$ind measure_executable.sh
done
