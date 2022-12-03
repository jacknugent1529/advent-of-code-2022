module Main where

import Data.Set (intersection, fromList, toList)
import Data.Char (Char, ord, isLower)

import Debug.Trace


-- part 1
splitStr :: String -> (String, String)
splitStr s =
    let
        l = (length s) `div` 2
        left = take l s
        right = drop l s
    in 
        (left,right)

getCommonCharacters :: (String, String) -> String
getCommonCharacters (l,r) = toList $ (fromList l) `intersection` (fromList r)

score :: Char -> Int
score c = 
    if isLower c then
        ord c - ord 'a' + 1
    else
        ord c - ord 'A' + 1 + 26

scorePack :: String -> Int
scorePack pack = sum . fmap score . getCommonCharacters $ splitStr $ pack

-- part 2
getGroups :: [String] -> [[String]]
getGroups (a:b:c:ds) = [a,b,c] : getGroups ds
getGroups _ = []

getCommonCharactersList :: [String] -> String
getCommonCharactersList g = toList $ foldl1 intersection (map fromList g)

scoreGroup :: [String] -> Int
scoreGroup = score . head . getCommonCharactersList

main :: IO ()
main = do
    input <- lines <$> getContents

    putStrLn "Part 1"
    print . sum . map scorePack $ input

    putStrLn "Part 2"
    print . sum . map scoreGroup . getGroups $ input
