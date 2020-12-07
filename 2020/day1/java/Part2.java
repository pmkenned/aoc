import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class Part2
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

        for (int i = 0 ; i < numbers.size(); i++) {
            for (int j = i+1 ; j < numbers.size(); j++) {
                int x = numbers.get(i);
                int y = numbers.get(j);
                Integer sought = 2020 - x - y;
                int idx = numbers.indexOf(sought);
                if (idx > j && idx != -1) {
                    System.out.println(x*y*numbers.get(idx));
                }
            }
        }
    }
}
