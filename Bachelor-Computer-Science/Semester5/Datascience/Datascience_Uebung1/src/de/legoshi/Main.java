package de.legoshi;

import de.legoshi.geometry.Circle;
import de.legoshi.geometry.GeometryObject;
import de.legoshi.geometry.Rectangle;
import de.legoshi.geometry.Square;

import java.util.ArrayList;

public class Main {

    public static void main(String args[]) {

        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(5, 10);
        Square square = new Square(2);

        ArrayList<GeometryObject> arrayList = new ArrayList<>();
        arrayList.add(circle);
        arrayList.add(rectangle);
        arrayList.add(square);

        double sum = 0;

        for(GeometryObject object : arrayList) {
            System.out.println("Klasse: " + object.getClass().toString());
            System.out.println("Umfang: " + object.calculateScope());
            System.out.println("Fläche: " + object.calculateArea());
            sum = object.calculateArea() + sum;
        }

        System.out.println("Flächeninhalt Summe: " + sum);

    }

}
