package testworld;

import testworld.wein.Schaumwein;
import testworld.wein.Wein;

import java.util.HashMap;

public class Testworld {

	public static void main(String[] args) {

		// TODO Auto-generated method stub
		System.out.println("Daniel war hier.");
		System.out.println("Benjamin war hier.");
		System.out.println("Mats war hier bby.");
		System.out.println("Yazar war hier :P");
		System.out.println("Jakob war hier :) ");
		
		BenjaminsKlasse benjamin = new BenjaminsKlasse("Benjamin", 20, "Das ist eine Nachricht!");
		BenjaminsKlasse daniel = new BenjaminsKlasse("Daniel", 20, "Ich bin DER DANIEL!");
		BenjaminsKlasse yazar = new BenjaminsKlasse("Yazar", 21, "WHAZZZZZUUUPP");
		BenjaminsKlasse patrick	= new BenjaminsKlasse("Patrick", 19, "Ich bin ein String");
		BenjaminsKlasse jakob = new BenjaminsKlasse("Jakob", 20, "'tis but a scratch!");
		
		HashMap<Integer, BenjaminsKlasse> integerBenjaminsKlasseHashMap = new HashMap<>();
		integerBenjaminsKlasseHashMap.put(1, benjamin);
		integerBenjaminsKlasseHashMap.put(2, daniel);

		benjamin.sagNamen();
		integerBenjaminsKlasseHashMap.get(2).sagNamen(); //daniel test
		
		power p = new power();
		System.out.println(p.CallMe(2));

		Wein blauwein = new Wein("Blauwein", "Blau", 2015); //erstelle Blauwein mit Wein Konstruktor
		Wein rotwein = new Wein("Rotwein", "Rot", 2016); //erstelle Rotwein mit Wein Konstruktor

		Schaumwein schaumweinBlau = new Schaumwein(blauwein, "Mit viel Blau"); //erstelle SchaumweinBlau mit Schauwein Konsturktor

		//gebe verschiedene Informationen zu den Objekten aus
		System.out.println("Farbe des Blauweins: " + blauwein.getFarbe());
		System.out.println("Farbe des Rotweins: " + rotwein.getFarbe());
		System.out.println("Alter des blauen Schaumweines: " + schaumweinBlau.getAlter());

	}

}
