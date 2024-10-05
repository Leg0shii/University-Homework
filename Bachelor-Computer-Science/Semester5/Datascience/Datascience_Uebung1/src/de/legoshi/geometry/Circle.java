package de.legoshi.geometry;

public class Circle implements GeometryObject{

    private int radius;

    public Circle(int radius) {
        this.radius = radius;
    }

    @Override
    public double calculateScope() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * Math.pow(radius, 2);
    }
}
