package com.company.SetAjutor;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class CompareFiles {

    private static final CompareFiles instance = new CompareFiles();

    private CompareFiles() {}

    public Boolean compareFiles(String fileName1, String fileName2) throws IOException {
        Path path1 = Path.of(fileName1);
        Path path2 = Path.of(fileName2);

        String file1 = Files.readString(path1);
        String file2 = Files.readString(path2);

        String[] list1, list2;

        list1 = file1.split(" ");
        list2 = file2.split(" ");

        if(list1.length != list2.length)
            return false;

        Boolean isInt;

        if(list1[0].indexOf('.') == -1)
            isInt = true;
        else isInt = false;

        for(int i = 0; i < list1.length; ++i) {
            if(isInt) {
                try {
                    Integer n1 = Integer.parseInt(list1[i]);
                    Integer n2 = Integer.parseInt(list2[i]);

                    if(n1 != n2)
                        return false;
                }
                catch (Exception ex) {
                    return false;
                }
            }
            else {
                try {
                    Double n1 = Double.parseDouble(list1[i]);
                    Double n2 = Double.parseDouble(list2[i]);

                    if(!n1.equals(n2))
                        return false;
                }
                catch (Exception ex) {
                    return false;
                }
            }
        }

        return true;
    }

    public static CompareFiles getInstance() {
        return instance;
    }

}
