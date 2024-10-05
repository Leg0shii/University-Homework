package com.company.cellautomate;

import java.util.Arrays;
import java.util.stream.Collectors;

public class Task2 {

    private int[] startPos;
    private int[] stepCount;

    private double averageSteps;
    private double standardDerivative;

    private int pos;

    public Task2() {
        this.startPos = new int[21*21];
        this.stepCount = new int[21*21];
        this.pos = 0;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public int[] getStartPos() {
        return startPos;
    }

    public void setStartPos(int[] startPos) {
        this.startPos = startPos;
    }

    public int[] getStepCount() {
        return stepCount;
    }

    public void setStepCount(int index, int count) {
        this.stepCount[index] = count;
    }

    public double getAverageSteps() {
        double total = 21*21;
        double sum = 0;
        for(int i : this.stepCount) {
            sum = sum + i;
        }
        return (sum / total);
    }

    public double getStandardDerivative() {
        double average = getAverageSteps();
        double total = 21*21;
        double val = 0;

        for(int i : this.stepCount) {
            val = val + Math.pow((i-average),2);
        }
        val = Math.sqrt((val / total));
        return val;
    }

    public int[] getCountForSteps() {

        int[] counts = new int[52];
        int[] steps = this.stepCount;

        for(int step : steps) counts[step]++;

        return counts;
    }

}
