let () =
    let ic = open_in "../input.txt" in
    try
        let line = input_line ic in
        print_endline line;
        flush stdout;
        close_in ic

    with e ->
        close_in_noerr ic;
        raise e
