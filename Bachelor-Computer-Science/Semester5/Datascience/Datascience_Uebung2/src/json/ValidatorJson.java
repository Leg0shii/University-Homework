package json;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.Scanner;

import org.everit.json.schema.Schema;
import org.everit.json.schema.ValidationException;
import org.everit.json.schema.loader.SchemaLoader;
import org.json.JSONObject;
import org.json.JSONTokener;

/**
 * 
 * @author hg
 * Aufgabe 2.2
 */
public class ValidatorJson {

	public static void main(String[] args) throws FileNotFoundException {
		if(ValidatorJson.isValid()) {
			System.out.println("Alles valide");
		}
	}
	
	public static boolean isValid(){
		try {
			//Eingabe: Schema
			JSONObject jsonSchema = new JSONObject(
					new JSONTokener(ValidatorJson.class.getResourceAsStream("/schema.json")));
			//Eingabe: Dokument
			JSONObject jsonSubject = new JSONObject(
					new JSONTokener(ValidatorJson.class.getResourceAsStream("/music_invalid.json")));
			
			Schema schema = SchemaLoader.load(jsonSchema);
			schema.validate(jsonSubject);
			return true;
		}catch(ValidationException e) {
			List<ValidationException> causes = e.getCausingExceptions();
			for(ValidationException ex: causes)
				ex.printStackTrace();
			return false;
		}
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
