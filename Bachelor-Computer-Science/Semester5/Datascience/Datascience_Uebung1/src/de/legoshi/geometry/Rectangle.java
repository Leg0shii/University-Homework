package de.legoshi.geometry;

public class Rectangle implements GeometryObject{

    private int sideA;
    private int sideB;

    public Rectangle(int sideA, int sideB) {
        this.sideA = sideA;
        this.sideB = sideB;
    }

    @Override
    public double calculateScope() {
        return 2*sideB+2*sideA;
    }

    @Override
    public double calculateArea() {
        return sideB*sideA;
    }
}
