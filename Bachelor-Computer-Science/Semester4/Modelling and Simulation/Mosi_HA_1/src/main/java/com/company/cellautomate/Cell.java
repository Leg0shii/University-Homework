package com.company.cellautomate;

public class Cell {

    private State state;
    private int wald;
    private int feuer;

    public Cell(State state) {
        this.state = state;
    }

    public State getState() {
        return state;
    }

    public void setState(State state) {
        this.state = state;
    }

    public int getWald() {
        return wald;
    }

    public void setWald(int wald) {
        this.wald = wald;
    }

    public int getFeuer() {
        return feuer;
    }

    public void setFeuer(int feuer) {
        this.feuer = feuer;
    }
}
