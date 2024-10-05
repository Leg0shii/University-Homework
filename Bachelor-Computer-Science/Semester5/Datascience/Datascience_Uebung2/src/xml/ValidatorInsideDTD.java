package xml;

import java.io.File;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

/**
 * 
 * @author hg
 * Aufgabe 1.2
 */
public class ValidatorInsideDTD {

	public static void main(String... args) throws ParserConfigurationException, SAXException, IOException{
		
		//Standard-Aufrufe
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		factory.setValidating(true);
		DocumentBuilder builder = factory.newDocumentBuilder();
		
		//Eingabedokument
		builder.parse(new File("res/music_invalid.xml"));
	
	}
}
