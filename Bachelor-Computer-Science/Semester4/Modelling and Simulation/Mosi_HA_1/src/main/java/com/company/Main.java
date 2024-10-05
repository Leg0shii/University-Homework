package com.company;

import com.company.cellautomate.CellMachine;
import com.company.cellautomate.Task2;
import com.company.cellautomate.Task3;
import com.company.gui.Window;

public class Main {

    public static CellMachine cellMachine;
    public static Window window;
    public static Task2 task2;
    public static Task3 task3;

    public static void main(String[] args) {
        cellMachine = new CellMachine();
        window = new Window(cellMachine);
        task2 = new Task2();
        task3 = new Task3();
    }
}
