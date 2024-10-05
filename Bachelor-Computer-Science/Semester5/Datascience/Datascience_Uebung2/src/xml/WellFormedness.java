package xml;

import java.io.File;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.xml.sax.SAXException;

/**
 * 
 * @author hg
 * Aufgabe 1.1
 */
public class WellFormedness {

	public static void main(String... args) throws ParserConfigurationException, SAXException, IOException{
		
		//Standard-Aufrufe
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		DocumentBuilder builder = factory.newDocumentBuilder();
		
		//Eingabedokument
		Document document = builder.parse(new File("res/music_not_wellformed.xml"));
		
		//Ausgabe
		System.out.println(document.getFirstChild().getNodeName());
	}
}
