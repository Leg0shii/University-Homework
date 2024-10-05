package lueckentext;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

public class Levenshtein {

	public static void main(String[] args) {
		
		Levenshtein ls = new Levenshtein();
		ls.runTestCases();

	}
	
	/**
	 * Testfälle zum Überprüfen des Codes.
	 */
	public void runTestCases() {
		ArrayList<String> listOne = new ArrayList<>();
		listOne.add("Answers");
		listOne.add("Sonmus");
		listOne.add("JENOVA");
		listOne.add("Prelude");
		
		ArrayList<String> listTwo = new ArrayList<>();
		listTwo.add("Somnus");
		listTwo.add("Prehlude");
		listTwo.add("J-E-N-O-V-A");
		listTwo.add("Answer");
		
		for(String s1: listOne) {
			int pos = calculateMinDistance(s1, listTwo);
			System.out.println(s1+" is most similar to "+listTwo.get(pos));
		}
	}
	
	/**
	 * Aufgabe 1.1
	 * Kosten einer Zeichenersetzung
	 * @param a Das erste Zeichen
	 * @param b Das zweite Zeichen
	 * @return 0, falls Zeichen identisch sind, 1 sonst
	 */
	public static int costOfSubstitution(char a, char b) {
		return a == b ? 0 : 1;
	}

	/**
	 * Aufgabe 1.2
	 * Berechnung der Levensthein-Distanz zwischen zwei Zeichenketten
	 * @param x Erste Zeichenkette
	 * @param y Zweite Zeichenkette
	 * @return Anzahl minimaler Änderungsoperationen
	 */
	public int calculateDistance(String x, String y) {

		if(x == null || x.equals("")) return y.length();
		if(y == null || y.equals("")) return x.length();
		
		String xSubstring = x.substring(1);
		String ySubstring = y.substring(1);

		int replace = calculateDistance(xSubstring, ySubstring) + costOfSubstitution(x.charAt(0), y.charAt(0));
		int addition = calculateDistance(x, ySubstring) + 1;
		int deletion = calculateDistance(xSubstring, y) + 1;

		return min(replace, addition, deletion);
	}

	/**
	 * Aufgabe 1.3
	 * Berechnung des Minimalabstandes einer Zeichenkette zu einer Menge von Zeichenketten
	 * @param value Die zu prüfende Zeichenkette
	 * @param compare Die Menge von zu vergleichenden Zeichenketten
	 * @return
	 */
	public int calculateMinDistance(String value, ArrayList<String> compare) {
		int minDistance = Integer.MAX_VALUE;
		int minPos = 0;
		int it = 0;

		for(String c: compare) {
			int dist = calculateDistance(value, c);
			if(dist <= minDistance) {
				minPos = it;
				minDistance = dist;
			}
			it++;
		}

		return minPos;
	}
	
	/**
	 * Hilfsfunktion: Ermittelung des Minimums aus einer Menge von ganzzahligen Werten
	 * @param numbers Menge von ganzzahligen Werten
	 * @return Das minimum, falls mindestends ein Wert eingegeben wurde, Integer.MAX_VALUE sonst
	 */
	public static int min(int... numbers) {
		if(numbers!= null)
			return Arrays.stream(numbers).min().getAsInt();
		else
			return Integer.MAX_VALUE;
	}
}
