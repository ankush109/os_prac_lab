BEGIN {FS="~"}; {NR>1;total1+=$3;total2+=$4;total3+=$5}; END {print "Average:", total1/(NR-1),total2/(NR-1),total3/(NR-1)}
