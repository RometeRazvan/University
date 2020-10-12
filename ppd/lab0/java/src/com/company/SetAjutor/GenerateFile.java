package com.company.SetAjutor;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.rmi.server.ExportException;
import java.util.Random;

public class GenerateFile {

    private static final GenerateFile instance = new GenerateFile();

    private GenerateFile() {}

    public void generate(String fileName, Integer size, Integer min, Integer max) throws IOException {
        File file = new File(fileName);

        if(file.createNewFile() != true) {
            file.delete();
            file.createNewFile();
        }

        for(int i = 0; i < size; ++i) {
            Random random = new Random();
            FileWriter fileWriter = new FileWriter(file.getName(), true);

            int nr = random.ints(min, max).findFirst().getAsInt();

            fileWriter.write(nr + " ");

            fileWriter.close();
        }
    }

    public static GenerateFile getInstance() {
        return instance;
    }

}
