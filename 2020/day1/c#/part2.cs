using System;

public class Part1
{
    public static void Main(string[] args)
    {
        string[] lines = System.IO.File.ReadAllLines(@"../input.txt");

        int[] numbers = new int[lines.Length];
        int idx=0;
        foreach (string line in lines) {
            numbers[idx++] = int.Parse(line);
        }

        for (int i = 0; i < numbers.Length; i++) {
            int n = numbers[i];
            for (int j = i+1; j < numbers.Length; j++) {
                int m = numbers[j];
                for (int k = j+1; k < numbers.Length; k++) {
                    int o = numbers[k];
                    if (n + m + o== 2020) {
                        Console.WriteLine(n*m*o);
                    }
                }
            }
        }
    }
}
