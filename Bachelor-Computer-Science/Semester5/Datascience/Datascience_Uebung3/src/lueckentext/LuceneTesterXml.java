package lueckentext;
import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.apache.lucene.analysis.de.GermanAnalyzer;
import org.apache.lucene.analysis.en.EnglishAnalyzer;
import org.apache.lucene.analysis.it.ItalianAnalyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field.Store;
import org.apache.lucene.document.StringField;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class LuceneTesterXml {
	
	static String indexEng = "indexXmlEngl/";
	static String indexLatin = "indexXmlLatin/";
	static String indexGerman = "indexXmlGerman/";
	static String input = "xml/songs.xml";
	
	public static void main(String... args) throws IOException, ParseException, XPathExpressionException, ParserConfigurationException, SAXException {
		// Index aufbauen (Hier: für alle Dokumente)
		LuceneTesterXml.indexDirectory();
		// Anfrage stellen
		LuceneTesterXml.search("Snap click clank whirr whizz wham boom", "english");
		LuceneTesterXml.search("Imperium", "latin");
		//LuceneTesterXml.search("justice", "english");
	}

	private static void indexDirectory() throws IOException, XPathExpressionException, ParserConfigurationException, SAXException {
		// Für jeweilige Sprache den Analyzer festlegen
		//Englisch
		Path pathEng = Paths.get(indexEng);
		Directory directoryEng = FSDirectory.open(pathEng);
		IndexWriterConfig configEngl = new IndexWriterConfig(new EnglishAnalyzer());
		IndexWriter indexWriterEngl = new IndexWriter(directoryEng, configEngl);
		
		//Latein
		Path pathLat = Paths.get(indexLatin);
		Directory directoryLatin = FSDirectory.open(pathLat);
		IndexWriterConfig configLat = new IndexWriterConfig(new ItalianAnalyzer());
		IndexWriter indexWriterLatin = new IndexWriter(directoryLatin, configLat);
		
		//Deutsch
		Path pathGer = Paths.get(indexGerman);
		Directory directoryGerman = FSDirectory.open(pathGer);
		IndexWriterConfig configGer = new IndexWriterConfig(new ItalianAnalyzer());
		IndexWriter indexWriterGerman = new IndexWriter(directoryGerman, configGer);
		
		//Vorherigen Index löschen
		indexWriterEngl.deleteAll();
		indexWriterLatin.deleteAll();
		indexWriterGerman.deleteAll();
		
		File f = new File(input);
		org.w3c.dom.Document doc = getDocumentFromFile(f);
		NodeList songs = evalXPath2NodeList(doc, "//songs");
		//Einzelne Songs auslesen
		for(int i=0; i<songs.getLength(); i++) {
			Node song = songs.item(i);
			Element element = (Element) song;
			
			String title = element.getElementsByTagName("title").item(0).getTextContent();
			String altTitle = element.getElementsByTagName("altTitle").item(0).getTextContent();
			String composer = element.getElementsByTagName("composer").item(0).getTextContent();
			String vocals = element.getElementsByTagName("vocals").item(0).getTextContent();
			String lyrics = element.getElementsByTagName("lyrics").item(0).getTextContent();
			String choir = element.getElementsByTagName("choir").item(0).getTextContent();
			String textEngl = element.getElementsByTagName("text").item(0).getTextContent();
			String textLatin = element.getElementsByTagName("text").item(0).getTextContent();
			String textGerman = element.getElementsByTagName("text").item(0).getTextContent();

			Document d = new Document();

			if(!textEngl.equals("") && textEngl != null) {
				d.add(new TextField("path", f.getName(), Store.YES));
				d.add(new TextField("contents", textEngl, Store.YES));
			}
			if(!textLatin.equals("") && textLatin != null) {
				d.add(new TextField("path", f.getName(), Store.YES));
				d.add(new TextField("contents", textLatin, Store.YES));
			}
			if(!textGerman.equals("") && textGerman != null) {
				d.add(new TextField("path", f.getName(), Store.YES));
				d.add(new TextField("contents", textGerman, Store.YES));
			}

			indexWriterEngl.addDocument(d);
		}
		
		indexWriterEngl.close();
		indexWriterLatin.close();
		indexWriterGerman.close();
		
		directoryEng.close();
		directoryLatin.close();
		directoryGerman.close();
	}

	private static void search(String text, String language) throws IOException, ParseException {

		// Zum Indexer passenden QueryParser anlegen und
		// Inhaltselemente der Dokumente abfragen
		QueryParser queryParser;
		IndexSearcher indexSearcher = null;
		switch(language) {
			case "english":{
				queryParser = new QueryParser("contents", new EnglishAnalyzer());
				Path path = Paths.get(indexEng);
				Directory directory = FSDirectory.open(path);
				IndexReader indexReader = DirectoryReader.open(directory);
				indexSearcher = new IndexSearcher(indexReader);
				break;
			}
			case "german":{
				queryParser = new QueryParser("contents", new GermanAnalyzer());
				Path path = Paths.get(indexGerman);
				Directory directory = FSDirectory.open(path);
				IndexReader indexReader = DirectoryReader.open(directory);
				indexSearcher = new IndexSearcher(indexReader);
				break;
			}
			case "latin":{
				queryParser = new QueryParser("contents", new ItalianAnalyzer());
				Path path = Paths.get(indexLatin);
				Directory directory = FSDirectory.open(path);
				IndexReader indexReader = DirectoryReader.open(directory);
				indexSearcher = new IndexSearcher(indexReader);
				break;
			}
			default:
				queryParser = null;
				break;
		}
		
		Query query = queryParser.parse(text);
		TopDocs topDocs = indexSearcher.search(query,10);
		int i = 0;
		for (ScoreDoc scoreDoc : topDocs.scoreDocs) {
			i++;
			Document document = indexSearcher.doc(scoreDoc.doc);
			switch(language) {
				case "english": System.out.println(i + ") Score: " + scoreDoc.score + "; Datei: " + document.get("path") + "; Inhalt: " + document.get("contents")); break;
				case "german": System.out.println(i + ") Score: " + scoreDoc.score + "; Datei: " + document.get("path") + "; Inhalt: " + document.get("contents")); break;
				case "latin": System.out.println(i + ") Score: " + scoreDoc.score + "; Datei: " + document.get("path") + "; Inhalt: " + document.get("contents")); break;
				default: break;
			}
			
		}
	}
	
	//Vorgefertigte Hilfsmethoden
	
	/**
	 * Aus XML-Datei ein W3C-DOM-Dokument erzeugen
	 * @param file XML-Datei
	 * @return W3C-DOM-Dokument
	 * @throws ParserConfigurationException
	 * @throws SAXException
	 * @throws IOException
	 */
	public static org.w3c.dom.Document getDocumentFromFile(File file) throws ParserConfigurationException, SAXException, IOException {
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		DocumentBuilder builder = factory.newDocumentBuilder();
		org.w3c.dom.Document document = builder.parse(file);
		return document;
	}
	
	/**
	 * Aus DOM via XPath einen Node erzeugen
	 * @param doc Das Ausgangsdokument
	 * @param expression Der XPath-Ausdruck
	 * @return Ein einzelner Node
	 * @throws XPathExpressionException
	 */
	public static Node evalXPath2Node(org.w3c.dom.Document doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		Node node = (Node) expr.evaluate(doc, XPathConstants.NODE);
		return node;
	}
	
	/**
	 * Aus DOM via XPath eine NodeList erzeugen
	 * @param doc Das Ausgangsdokument
	 * @param expression Der XPath-Ausdruck
	 * @return Eine NodeList
	 * @throws XPathExpressionException
	 */
	public static NodeList evalXPath2NodeList(org.w3c.dom.Document doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		NodeList node = (NodeList) expr.evaluate(doc, XPathConstants.NODESET);
		return node;
	}
	
	/**
	 * Aus DOM via XPath einen String erzeugen
	 * @param doc Das Ausgangsdokument
	 * @param expression Der XPath-Ausdruck
	 * @return Ein String
	 * @throws XPathExpressionException
	 */
	public static String evalXPath2String(org.w3c.dom.Document doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		String node = (String) expr.evaluate(doc, XPathConstants.STRING);
		return node;
	}
	
	/**
	 * Aus Node via XPath einen neuen Node erzeugen
	 * @param doc Der Ausgangsknoten
	 * @param expression Der XPath-Ausdruck
	 * @return Ein einzelner Node
	 * @throws XPathExpressionException
	 */
	public static Node evalXPath2Node(Node doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		Node node = (Node) expr.evaluate(doc, XPathConstants.NODE);
		return node;
	}
	
	/**
	 * Aus Node via XPath eine NodeList erzeugen
	 * @param doc Der Ausgangsknoten
	 * @param expression Der XPath-Ausdruck
	 * @return Eine NodeList
	 * @throws XPathExpressionException
	 */
	public static NodeList evalXPath2NodeList(Node doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		NodeList node = (NodeList) expr.evaluate(doc, XPathConstants.NODESET);
		return node;
	}
	
	/**
	 * Aus Node via XPath einen String erzeugen
	 * @param doc Der Ausgangsknoten
	 * @param expression Der XPath-Ausdruck
	 * @return Ein String
	 * @throws XPathExpressionException
	 */
	public static String evalXPath2String(Node doc, String expression) throws XPathExpressionException {
		XPathFactory xPathfactory = XPathFactory.newInstance();
		XPath xpath = xPathfactory.newXPath();
		XPathExpression expr = xpath.compile(expression);
		String node = (String) expr.evaluate(doc, XPathConstants.STRING);
		return node;
	}
}
