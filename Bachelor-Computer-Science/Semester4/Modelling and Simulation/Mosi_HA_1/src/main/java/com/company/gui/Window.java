package com.company.gui;

import com.company.Main;
import com.company.cellautomate.Cell;
import com.company.cellautomate.CellMachine;
import com.company.cellautomate.State;

import javax.swing.*;
import java.awt.*;

public class Window extends JFrame {

    CellMachine cellMachine;
    Container container;
    public JButton[][] jButtons;

    public JButton jButton_size = new JButton();
    public JButton jButton_step = new JButton();
    public JButton jButton_run = new JButton();
    public JButton jButton_speed = new JButton();

    public JButton jButton_init2 = new JButton();
    public JButton jButton_init3 = new JButton();
    public JButton jButton_random = new JButton();

    JTextField xSize = new JTextField();
    JTextField ySize = new JTextField();

    JTextField speed = new JTextField();

    public int waitTime = 1000; //in ms

    int frameWidth;
    int frameHeight;

    public Window(CellMachine cellMachine) {
        this.jButtons = new JButton[cellMachine.getSpalte()][cellMachine.getZeile()];
        this.cellMachine = cellMachine;

        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        this.frameWidth = 500;
        this.frameHeight = 850;
        setSize(frameWidth, frameHeight);

        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (d.width - getSize().width) / 2;
        int y = (d.height - getSize().height) / 2;
        setLocation(x, y);

        setTitle("Cell Automate");
        setResizable(false);

        Container cp = getContentPane();
        cp.setLayout(null);
        this.container = cp;

        jButton_size.setText("Set new size!");
        jButton_size.setBounds(100, 500, 150, 30);
        jButton_size.addActionListener(e -> {
            deleteButtons();
            int zeile = Integer.parseInt(xSize.getText());
            int spalte = Integer.parseInt(ySize.getText());
            cellMachine.setZeile(zeile);
            cellMachine.setSpalte(spalte);
            cellMachine.setField(new Cell[zeile][spalte]);
            generateButtons(false);
            dispose();
            setVisible(true);
        });
        cp.add(jButton_size);

        jButton_speed.setText("Set speed in ms!");
        jButton_speed.setBounds(100, 540, 150, 30);
        jButton_speed.addActionListener(e -> waitTime = Integer.parseInt(speed.getText()));
        cp.add(jButton_speed);

        jButton_step.setText("Next step!");
        jButton_step.setBounds(100, 580, 150, 30);
        jButton_step.addActionListener(e -> cellMachine.applyRule());
        cp.add(jButton_step);

        jButton_run.setText("Run!");
        jButton_run.setBounds(100, 620, 150, 30);
        jButton_run.addActionListener(e -> {
            cellMachine.applyRuleN();
        });
        cp.add(jButton_run);

        jButton_init2.setText("Init 2");
        jButton_init2.setBounds(100, 660, 150, 30);
        jButton_init2.addActionListener(e -> {
            for (int h = 0; h < 21 * 21; h++) {
                deleteButtons();
                cellMachine.setZeile(21);
                cellMachine.setSpalte(21);
                Cell[][] cells = new Cell[21][21];
                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 21; j++) {
                        if (j <= 10) cells[i][j] = new Cell(State.Wiese);
                        else cells[i][j] = new Cell(State.Wald);
                    }
                }
                this.jButtons = new JButton[21][21];
                cells[(int) Math.floor(Main.task2.getPos() / 21)][Main.task2.getPos() % 21] = new Cell(State.Feuer);
                cellMachine.setField(cells);
                generateButtons(true);
                // dispose();
                // setVisible(true);

                cellMachine.applyRuleN();
            }
            int[] cs = Main.task2.getCountForSteps();
            for (int i = 0; i < 50; i++) {
                String length = "";
                for (int l = 0; l < cs[i]; l++) {
                    length = length + "*";
                }
                System.out.println(i + ": " + length);
            }
            System.out.println("Steps: " + Main.task2.getAverageSteps());
            System.out.println("Steps: " + Main.task2.getStandardDerivative());
        });
        cp.add(jButton_init2);

        jButton_init3.setText("Init 3");
        jButton_init3.setBounds(100, 700, 150, 30);
        jButton_init3.addActionListener(e -> {

            for (int h = 0; h < 10000; h++) {
                deleteButtons();
                cellMachine.setZeile(21);
                cellMachine.setSpalte(21);
                Cell[][] cells = new Cell[21][21];
                for (int i = 0; i < 21; i++) {
                    for (int j = 0; j < 21; j++) {
                        double num = Math.random();
                        if (num <= 0.33) cells[i][j] = new Cell(State.Wiese);
                        if (num > 0.33 && num <= 0.66) cells[i][j] = new Cell(State.Wald);
                        if (num > 0.66) cells[i][j] = new Cell(State.Feuer);
                    }
                }
                this.jButtons = new JButton[21][21];
                cellMachine.setField(cells);
                generateButtons(true);
                cellMachine.applyRuleN();
            }
            int[] cs = Main.task3.getCountForSteps();
            for (int i = 0; i < 100; i++) {
                String length = "";
                for (int l = 0; l < cs[i]; l++) {
                    length = length + "*";
                }
                System.out.println(i + ": " + length);
            }
            System.out.println("AvgSteps: " + Main.task3.getAverageSteps());
            System.out.println("DevSteps: " + Main.task3.getStandardDerivative());

        });

        cp.add(jButton_init3);

        xSize.setText("3");
        xSize.setBounds(300,500,30,30);
        cp.add(xSize);

        ySize.setText("3");
        ySize.setBounds(350,500,30,30);
        cp.add(ySize);

        speed.setText("1000");
        speed.setBounds(300,540,80,30);
        cp.add(speed);

    generateButtons(false);

    setVisible(true);

}

    public void generateButtons(boolean b) {
        int zeile = cellMachine.getZeile();
        int spalte = cellMachine.getSpalte();
        this.jButtons = new JButton[zeile][spalte];

        int lenY = (frameWidth) / (zeile + 2);
        int lenX = 500 / (spalte + 2);
        int offsetX = lenX;
        int offsetY = lenY;

        for (int i = 0; i < zeile; i++) {
            for (int j = 0; j < spalte; j++) {
                JButton jButton = new JButton();
                jButton.setBounds(offsetX, offsetY, lenX, lenY);
                if (b) jButton.setBackground(cellMachine.stateToColor(cellMachine.getField()[i][j].getState()));
                else jButton.setBackground(Color.GREEN);
                jButton.addActionListener(e -> {
                    Color background = jButton.getBackground();
                    if (Color.ORANGE.equals(background)) {
                        jButton.setBackground(Color.GREEN);
                    } else if (Color.GREEN.equals(background)) {
                        jButton.setBackground(Color.RED);
                    } else {
                        jButton.setBackground(Color.ORANGE);
                    }
                });
                jButtons[i][j] = jButton;
                this.container.add(jButton);
                offsetX = offsetX + lenX;
            }
            offsetX = lenX;
            offsetY = offsetY + lenY;
        }
    }

    private void deleteButtons() {
        for (int i = 0; i < cellMachine.getZeile(); i++) {
            for (int j = 0; j < cellMachine.getSpalte(); j++) {
                container.remove(jButtons[i][j]);
            }
        }
    }

}
