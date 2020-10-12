package com.company.Tests;

import com.company.SetAjutor.CompareFiles;
import com.company.SetAjutor.GenerateFile;

import java.nio.file.Files;
import java.nio.file.Path;

public class TestAll {
    public void testGenerateFile() {
        String fileName = "test1.txt";
        Integer size = 100, min = 1, max = 100;

        GenerateFile generateFile = GenerateFile.getInstance();

        try {
            generateFile.generate(fileName, size, min, max);

            Path path = Path.of(fileName);
            String file = Files.readString(path);

            String[] list = file.split(" ");

            if(list.length != size)
                throw new Exception("A fost generat un numar incorect de date");

            for(int i = 0; i < list.length; ++i) {
                Integer nr = Integer.parseInt(list[i]);

                if(nr < min || nr > max)
                    throw new Exception("Datele nu sunt incluse in intervalul precizat");
            }
        }
        catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void testCompareFiles() {
        try {
            String fileName2 = "test2.txt";
            String fileName3 = "test3.txt";
            String fileName4 = "test4.txt";
            String fileName5 = "test5.txt";

            CompareFiles compareFiles = CompareFiles.getInstance();

            if(compareFiles.compareFiles(fileName2, fileName3) == false)
                throw new Exception("Validate fisiere identice invalida !!");

            if(compareFiles.compareFiles(fileName4, fileName5) == true)
                throw new Exception("Validate fisiere diferita invalida !!");
        }
        catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void testAll() {
        this.testGenerateFile();
        this.testCompareFiles();
    }
}
