package xml;

import java.io.File;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 *
 * @author hg
 * Aufgabe 1.3
 */
public class XPathEvaluator {
	
	public static void main(String... args){
		File inputFile = new File("res/music_correct.xml"); //Eingabedatei

		String anfrage1 = "//track/title";
		String anfrage2 = "//track[composer/text()='Nobuo Uematsu']/title";
		String anfrage3 = "sum(//track/@length)";

		String xpath = anfrage3; //XPath-Anfrage
		XPathEvaluator xpe = new XPathEvaluator();
		xpe.eval(inputFile, xpath);
	}
	
	public void eval(File inputFile, String expression){
		try {
			//Standard-Aufrufe
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder;
			dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(inputFile);
			doc.getDocumentElement().normalize();
			XPath xPath =  XPathFactory.newInstance().newXPath();

			//Für Mengen
			/* NodeList nodeList = (NodeList) xPath.compile(expression).evaluate(doc, XPathConstants.NODESET);
			for (int i = 0; i < nodeList.getLength(); i++) {
				Node nNode = nodeList.item(i);
				System.out.println(nNode.getNodeName()+": "+nNode.getTextContent());
			} */
			
			//Für einzelne Werte
			double node = (Double)(xPath.compile(expression).evaluate(doc, XPathConstants.NUMBER));
			System.out.println(node);

			
		} catch (Exception e){
			e.printStackTrace();
		}
	}
}
