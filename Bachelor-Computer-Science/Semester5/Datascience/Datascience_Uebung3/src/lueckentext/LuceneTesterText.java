package lueckentext;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;

import org.apache.lucene.analysis.de.GermanAnalyzer;
import org.apache.lucene.analysis.en.EnglishAnalyzer;
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

public class LuceneTesterText {
	
	static String index = "index/";
	static String input = "docs/";
	
	public static void main(String... args) throws IOException, ParseException {
		// Index aufbauen (Hier: f r alle Dokumente)
		LuceneTesterText.indexDirectory();
		// Anfrage stellen
		LuceneTesterText.search("Snap click clank whirr whizz wham boom");
	}

	private static void indexDirectory() throws IOException {
		// Index anlegen
		System.out.println(new File("./").getAbsolutePath());
		Path path = Paths.get("C:/Users/supid/IdeaProjects/Datascience_Uebung3/docs");
		Directory directory = FSDirectory.open(path);
		// F r jeweilige Sprache den Analyzer festlegen
		IndexWriterConfig config = new IndexWriterConfig(new EnglishAnalyzer());
		IndexWriter indexWriter = new IndexWriter(directory, config);
		indexWriter.deleteAll();
		File f = new File("C:/Users/supid/IdeaProjects/Datascience_Uebung3/docs");
		for (File file : f.listFiles()) {
			if(file.getName().contains(".txt")) {
				System.out.println(file.getAbsolutePath());
				Document doc = new Document();
				doc.add(new StringField("path", file.getName(), Store.YES));
				String text = readFile(file.getAbsolutePath());

				doc.add(new TextField("contents", text, Store.YES));
				indexWriter.addDocument(doc);
			}
		}
		indexWriter.close();
		directory.close();
	}

	private static void search(String text) throws IOException, ParseException {
		Path path = Paths.get("C:/Users/supid/IdeaProjects/Datascience_Uebung3/docs");
		Directory directory = FSDirectory.open(path);
		IndexReader indexReader = DirectoryReader.open(directory);
		IndexSearcher indexSearcher = new IndexSearcher(indexReader);
		// Zum Indexer passenden QueryParser anlegen und
		// Inhaltselemente der Dokumente abfragen
		QueryParser queryParser = new QueryParser("contents", new EnglishAnalyzer());
		Query query = queryParser.parse(text);
		//Top-Ergebnisse erzeugen und ausgeben
		TopDocs topDocs = indexSearcher.search(query, 10);
		int i = 0;
		for (ScoreDoc scoreDoc : topDocs.scoreDocs) {
			i++;
			Document document = indexSearcher.doc(scoreDoc.doc);
			System.out.println(i + ") Score: " + scoreDoc.score + "; Datei: " + document.get("path") + "; Inhalt: " + document.get("contents"));
		}
	}
	
	/**
	 * Hilfmethode zum Umwandeln einer Datei in einen String 
	 * @param path Pfad zur Datei
	 * @return Ausgabe als String
	 * @throws IOException
	 */
	public static String readFile(String path) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(path));
		String everything = "";
		try {
		    StringBuilder sb = new StringBuilder();
		    String line = br.readLine();

		    while (line != null) {
		        sb.append(line);
		        sb.append(System.lineSeparator());
		        line = br.readLine();
		    }
		    everything = sb.toString();
		    
		} finally {
		    br.close();
		}
		return everything;
	}
}
