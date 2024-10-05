package json;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * 
 * @author hg
 * Aufgabe 2.1
 */
public class WellFormednessJson {

	public static void main(String[] args) throws FileNotFoundException {
		//Eingabedokument
		if(WellFormednessJson.isJSONWellFormed("res/music_not_wellformed.json")) {
			System.out.println("Alles wohlgeformt");
		}
	}
	
	public static boolean isJSONWellFormed(String file) throws FileNotFoundException {
		String test = WellFormednessJson.readFile(file);
		//Das Dokument ist entweder ein Objekt oder ein Array
		try {
			new JSONObject(test);
		} catch (JSONException ex) {
			System.err.println(ex.toString());
			try {
				
				new JSONArray(test);
			} catch (JSONException ex1) {
				System.err.println(ex1.toString());
				return false;
			}
			return false;
		}
		return true;
	}
	
	/**
	 * Hilfsmethode zum Einlesen der Datei
	 * @param path Pfad zur Datei
	 * @return Zeichenkettenrepräsentation der Eingabedatei
	 * @throws FileNotFoundException
	 */
	public static String readFile(String path) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(path));
		String text = scanner.useDelimiter("\\A").next();
		scanner.close();
		return text;
	}

}
