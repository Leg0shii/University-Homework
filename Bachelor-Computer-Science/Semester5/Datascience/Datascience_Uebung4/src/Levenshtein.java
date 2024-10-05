import java.util.ArrayList;
import java.util.Arrays;

public class Levenshtein {

	public static void main(String[] args) {
		
		Levenshtein ls = new Levenshtein();
		ls.runTestCases();

	}
	
	/**
	 * Testfälle zum Überprüfen des Codes.
	 */
	public void runTestCases() {
		ArrayList<String> listOne = new ArrayList<String>();
		listOne.add("Answers");
		listOne.add("Sonmus");
		listOne.add("JENOVA");
		listOne.add("Prelude");
		
		ArrayList<String> listTwo = new ArrayList<String>();
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
	 * Berechnung der Levensthein-Distanz zwischen zwei Zeichenketten
	 * @param x Erste Zeichenkette
	 * @param y Zweite Zeichenkette
	 * @return Anzahl minimaler Änderungsoperationen
	 */
	public int calculateDistance(String x, String y) {
		if (x == null || x.equals(""))
			return y.length();

		if (y == null || y.equals(""))
			return x.length();
		
		String xSubstring = x.substring(1);
		String ySubstring = y.substring(1);

		int replace = calculateDistance(xSubstring, ySubstring) + costOfSubstitution(x.charAt(0), y.charAt(0));
		int addition = calculateDistance(x, ySubstring) + 1;
		int deletion = calculateDistance(xSubstring, y) + 1;

		return min(replace, addition, deletion);
	}

	/**
	 * Kosten einer Zeichenersetzung
	 * @param a Das erste Zeichen
	 * @param b Das zweite Zeichen
	 * @return 0, falls Zeichen identisch sind, 1 sonst
	 */
	public int costOfSubstitution(char a, char b) {
		return a == b ? 0 : 1;
	}

	/**
	 * Hilfsfunktion: Ermittelung des Minimums aus einer Menge von ganzzahligen Werten
	 * @param numbers Menge von ganzzahligen Werten
	 * @return Das minimum, falls mindestends ein Wert eingegeben wurde, Integer.MAX_VALUE sonst
	 */
	public int min(int... numbers) {
		if(numbers!= null)
			return Arrays.stream(numbers).min().getAsInt();
		else
			return Integer.MAX_VALUE;
	}
	
	/**
	 * Berechnung des Minimalabstandes einer Zeichenkette zu einer Menge von Zeichenketten
	 * @param value Die zu prüfende Zeichenkette
	 * @param compare Die Menge von zu vergleichenden Zeichenketten
	 * @return
	 */
	public int calculateMinDistance(String value, ArrayList<String> compare) {
		int minDistance = Integer.MAX_VALUE;
		int minPos = 0;
		for(String c: compare) {
			int current = calculateDistance(value, c);
			if(current <= minDistance) {
				minDistance = current;
				minPos = compare.indexOf(c);
			}
		}
		return minPos;
	}

}
