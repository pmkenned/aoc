#!/usr/bin/awk -f
BEGIN{
    FS = ":"
    OFS = ";"
}

{
    for (i=1; i<NF; i++)
        print $i
}

END{

}
