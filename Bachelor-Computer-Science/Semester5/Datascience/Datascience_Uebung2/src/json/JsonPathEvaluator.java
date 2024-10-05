package json;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedHashMap;
import java.util.Scanner;

import com.jayway.jsonpath.JsonPath;

import net.minidev.json.JSONArray;

/**
 * 
 * @author hg
 * Aufgabe 2.3
 */
public class JsonPathEvaluator {

	public static void main(String[] args) throws FileNotFoundException {
		
		//JSON-Path-Ausdruck
		String jsonpath1 = "$..composer"; //OK
		String jsonpath2 = "$.music.album[0].tracks.track[*].title";
		
		//Eingabedatei
		String content = readFile("music_correct.json");
		
		//LinkedHashMap s = JsonPath.read(content, jsonpath1);
		JSONArray s = JsonPath.read(content, jsonpath2);
		//String s = JsonPath.read(content, jsonpath1);
		//Ausgabe
		System.out.println(s);
	}
	
	public static String readFile(String path) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(path));
		String text = scanner.useDelimiter("\\A").next();
		scanner.close();
		return text;
	}

}
