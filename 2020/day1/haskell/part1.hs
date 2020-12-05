import System.IO

-- True, False
-- &&, ||, not
-- ==, /=
-- succ, min, max, 

zs = [1,2,3]

doubleSmall x = if x > 100
                then x
                else x*2

foo :: (Integral a) => a -> Int
foo 4 = 5
foo x = 3

main :: IO()
main = do
    --putStr "Name: "
    --hFlush stdout
    --name <- getLine
    --putStrLn ("Hi " ++ name)
    print (foo 4)
    print (foo 0)
    print (min 3 4)
    let xs = [5,2,8]
    print (xs ++ zs)
