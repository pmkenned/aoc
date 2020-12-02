import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class Part1
{

    private static List<Integer> readFile()
    {
        List<Integer> numbers = new ArrayList<Integer>();
        try {
            File inputFile = new File("../input.txt");
            Scanner inputScanner = new Scanner(inputFile);
            while (inputScanner.hasNextLine()) {
                String line = inputScanner.nextLine();
                int x = Integer.parseInt(line);
                numbers.add(x);
            }
            inputScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Cannot open file");
        }
        return numbers;
    }

    public static void main(String[] args)
    {
        List<Integer> numbers = readFile();
        Collections.sort(numbers);

        for (Integer i : numbers) {
            Integer sought = 2020 - i;
            int idx = numbers.indexOf(sought);
            if (idx != -1) {
                System.out.println(i*numbers.get(idx));
            }
        }
    }
}
