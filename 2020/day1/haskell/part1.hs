import System.IO
import Data.List

f :: Integer -> [Integer] -> Integer
f x [] = 1
f x xs = let z = head xs in if elem (x-z) (tail xs) then z*(x-z) else 1

main :: IO()
main = do
    handle <- openFile "../input.txt" ReadMode
    contents <- hGetContents handle
    let lines = words contents
    let nums = (map read lines) :: [Integer]
    let z = map (f 2020) (tails nums)
    print (foldr (*) 1 z)
