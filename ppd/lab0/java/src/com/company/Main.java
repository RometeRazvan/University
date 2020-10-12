package com.company;

import com.company.SetAjutor.CompareFiles;
import com.company.SetAjutor.GenerateFile;
import com.company.Tests.TestAll;

import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        CompareFiles compareFiles = CompareFiles.getInstance();


        new TestAll().testAll();
    }
}
