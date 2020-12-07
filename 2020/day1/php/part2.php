#!/usr/bin/php
<?php
function get_numbers()
{
    $numbers = array();
    $infile = fopen("../input.txt", "r") or die("cannot open file");
    while (!feof($infile)) {
        $s = fgets($infile);
        array_push($numbers, (int)$s);
    }
    fclose($infile);
    return $numbers;
}

$numbers = get_numbers();

$len = count($numbers);
$done = 0;
for ($i=0; $i<$len; $i++) {
    $n = $numbers[$i];
    for ($j=$i+1; $j<$len; $j++) {
        $m = $numbers[$j];
        for ($k=$j+1; $k<$len; $k++) {
            $o = $numbers[$k];
            if ($n + $m + $o == 2020) {
                echo $n*$m*$o."\n";
                $done = 1;
                break;
            }
        }
        if ($done)
            break;
    }
    if ($done)
        break;
}
?>
