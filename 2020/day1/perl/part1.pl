#!/usr/bin/perl

use strict;
use warnings;

open(my $fh, "<", "../input.txt") or die $!;

my @lines = <$fh>;
chomp @lines;

for (my $i=0; $i < $#lines; $i++) {
    my $n = $lines[$i];
    for (my $j=$i+1; $j < $#lines; $j++) {
        my $m = $lines[$j];
        if ($n + $m == 2020) {
            print $n*$m . "\n";
        }
    }
}
