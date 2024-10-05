package com.company.cellautomate;

import com.company.Main;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class CellMachine {

    private Cell[][] field;
    private Cell[][] prevField;
    private int zeile;
    private int spalte;

    private int steps;

    public CellMachine() {
        this.field = new Cell[3][3];
        this.zeile = 3;
        this.spalte = 3;
    }

    public void applyRuleN() {
        int step = 0;
        while (true) {
            applyRule();
            step++;
            if (compareFields(getField(), getPrevField())) {
                System.out.println(Main.task3.getPos() + "No changes - Ending simulation");
                Main.task3.setStepCount(Main.task3.getPos(), step);
                Main.task3.setPos(Main.task3.getPos()+1);
                break;
            }
        }
    }

    public void eachCellFire() {


    }

    public void applyRule() {
        Cell[][] newField = this.field;
        getStateFromWindow(Main.window.jButtons);
        setOldField();
        setAllNeighbors();
        for (int i = 0; i < zeile; i++) {
            for (int j = 0; j < spalte; j++) {
                int wald = this.field[i][j].getWald();
                int feuer = this.field[i][j].getFeuer();
                if (this.field[i][j].getState().equals(State.Wiese)) {
                    if (wald >= 2) {
                        newField[i][j].setState(State.Wald);
                    }
                    if (feuer >= 1) {
                        newField[i][j].setState(State.Feuer);
                    }
                }
                if (this.field[i][j].getState().equals(State.Wald)) {
                    if (feuer >= 3) {
                        newField[i][j].setState(State.Feuer);
                    }
                }
            }
        }
        printBoard(Main.window.jButtons);
        this.field = newField;
    }

    private void setOldField() {
        Cell[][] cell = new Cell[this.zeile][this.spalte];
        for (int i = 0; i < this.zeile; i++) {
            for (int j = 0; j < this.spalte; j++) {
                cell[i][j] = new Cell(this.field[i][j].getState());
            }
        }
        this.prevField = cell;
    }

    private boolean compareFields(Cell[][] field1, Cell[][] field2) {
        for (int i = 0; i < this.zeile; i++) {
            for (int j = 0; j < this.spalte; j++) {
                if (field1[i][j].getState() != field2[i][j].getState()) return false;
            }
        }
        return true;
    }

    private void setAllNeighbors() {
        for (int i = 0; i < zeile; i++) {
            for (int j = 0; j < spalte; j++) {
                setNeighbor(i, j);
            }
        }
    }

    private void setNeighbor(int currZeile, int currSpalte) {
        ArrayList<Cell> arrayList = new ArrayList<>();
        for (int i = currZeile - 1; i <= currZeile + 1; i++) {
            for (int j = currSpalte - 1; j <= currSpalte + 1; j++) {
                if (i >= 0 && i < this.zeile && j >= 0 && j < this.spalte && (i != currZeile || j != currSpalte)) {
                    arrayList.add(this.field[i][j]);
                }
            }
        }
        int wald = (int) arrayList.stream().filter(c -> c.getState().equals(State.Wald)).count();
        int feuer = (int) arrayList.stream().filter(c -> c.getState().equals(State.Feuer)).count();
        this.field[currZeile][currSpalte].setWald(wald);
        this.field[currZeile][currSpalte].setFeuer(feuer);
    }

    private Cell toCell(String s) {
        return switch (s) {
            case "v" -> new Cell(State.Wiese);
            case "f" -> new Cell(State.Feuer);
            default -> new Cell(State.Wald);
        };
    }

    public void printBoard(JButton[][] jButtons) {
        for (int i = 0; i < zeile; i++) {
            for (int j = 0; j < spalte; j++) {
                jButtons[i][j].setBackground(stateToColor(this.field[i][j].getState()));
            }
        }
    }

    private void getStateFromWindow(JButton[][] jButtons) {
        for (int i = 0; i < zeile; i++) {
            for (int j = 0; j < spalte; j++) {
                this.field[i][j] = new Cell(colorToState(jButtons[i][j].getBackground()));
            }
        }
    }

    public State colorToState(Color color) {
        if (color.equals(Color.ORANGE)) return State.Wiese;
        if (color.equals(Color.GREEN)) return State.Wald;
        return State.Feuer;
    }

    public Color stateToColor(State state) {
        if (state.equals(State.Wald)) return Color.GREEN;
        if (state.equals(State.Feuer)) return Color.RED;
        return Color.ORANGE;
    }

    public int getZeile() {
        return zeile;
    }

    public int getSpalte() {
        return spalte;
    }

    public Cell[][] getField() {
        return field;
    }

    public Cell[][] getPrevField() {
        return prevField;
    }

    public void setZeile(int zeile) {
        this.zeile = zeile;
    }

    public void setSpalte(int spalte) {
        this.spalte = spalte;
    }

    public void setField(Cell[][] field) {
        this.field = field;
    }

    public int getSteps() {
        return steps;
    }

    public void setSteps(int steps) {
        this.steps = steps;
    }
}
