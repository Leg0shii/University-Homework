package lueckentext;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class SchemaMatching {
	
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		SchemaMatching.getMapping();
	}
	
	/**
	 * Haupfunktion: Schema auslesen, Mapping erzeugen und ausgeben
	 * @throws ClassNotFoundException
	 * @throws SQLException
	 */
	public static void getMapping() throws ClassNotFoundException, SQLException {
		Connection c = PostgresConnection.getConnection();
		DatabaseMetaData dbmd = c.getMetaData();
		ArrayList<TableInformation> schema1 = getSchemaInformation("s1", dbmd);
		ArrayList<TableInformation> schema2 = getSchemaInformation("s2", dbmd);

		System.out.println(schema1);
		System.out.println(schema2);
		
		ArrayList<ArrayList<Double>> matrix = getDistanceMatrix(schema1, schema2);
		
		for(int i=0; i< matrix.size(); i++) {
			ArrayList<Double> outer = matrix.get(i);
			double minimum = Double.MAX_VALUE;
			int minPos = 0;
			//TODO Ermittelung der Relation mit dem geringsten Abstand
			System.out.println("s1."+schema1.get(i).getName() + " maps to " + "s2."+schema2.get(minPos).getName() + " with similarity: " + (1-minimum));
		}
		
	}
	
	/**
	 * Aufgabe 2
	 * Ermittelung des Abstandes zwischen zwei Datentypen (inkl. dessen Länge)
	 * @param type1 Der erste Datentyp
	 * @param type2 Der zweite Datentyp
	 * @param size1 Die Länge des ersten Datentypens
	 * @param size2 Die Länge des zweiten Datentypens
	 * @return
	 */
	public static double typeDistance(String type1, String type2, long size1, long size2) {
		switch(type1) {
			case "int4": {
				switch (type2) {
					case "int4" -> {
						return Math.abs(size1 - size2) / (size1 + size2);
					}
					case "varchar" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "text" -> {
						return 0.9 + 0.1 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "float8" -> {
						return 0.5 + 0.5 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "date" -> {
						return 0.6 + 0.4 * Math.abs(size1 - size2) / (size1 + size2);
					}
				}
			}
			case "varchar": {
				switch(type2) {
					case "int4" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "varchar" -> {
						return Math.abs(size1 - size2) / (size1 + size2);
					}
					case "text" -> {
						return 0.5 + 0.5 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "float8" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "date" -> {
						return 0.7 + 0.3 * Math.abs(size1 - size2) / (size1 + size2);
					}
				}
			}
			case "text": {
				switch(type2) {
					case "int4" -> {
						return 0.9 + 0.1 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "varchar" -> {
						return 0.5 + 0.5 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "text" -> {
						return Math.abs(size1 - size2) / (size1 + size2);
					}
					case "float8" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "date" -> {
						return 0.7 + 0.3 * Math.abs(size1 - size2) / (size1 + size2);
					}
				}
			}
			case "float8": {
				switch(type2) {
					case "int4" -> {
						return 0.5 + 0.5 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "varchar" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "text" -> {
						return 0.8 + 0.2 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "float8" -> {
						return Math.abs(size1 - size2) / (size1 + size2);
					}
					case "date" -> {
						return 0.6 + 0.4 * Math.abs(size1 - size2) / (size1 + size2);
					}
				}
			}
			case "date": {
				switch(type2) {
					case "int4" -> {
						return 0.6 + 0.4 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "varchar" -> {
						return 0.7 + 0.3 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "text" -> {
						return 0.7 + 0.3 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "float8" -> {
						return 0.6 + 0.4 * Math.abs(size1 - size2) / (size1 + size2);
					}
					case "date" -> {
						return Math.abs(size1 - size2) / (size1 + size2);
					}
				}
			}
			default: return 1;
		}
	}
	
	/**
	 * Aufgabe 3
	 * Ermittelung des Abstandes zwischen zwei einzelnen Attributen aus zwei verschiedenen Relationen
	 * @param ci1 Das erste Attribut
	 * @param ci2 Das zweite Attribut
	 * @return Der Abstand zwischen beiden Attributen
	 */
	public static double getColumnDistance(ColumnInformation ci1, ColumnInformation ci2) {
		
		
		double d1 =
		double d2 = //TODO: Distanz der Positionen berechnen
		double d3 = //TODO: Distanz der Typen berechnen
		
		double w1 = 4;
		double w2 = 1;
		double w3 = 5;
		
		return //TODO Gewichtete, aufsummierte nund normierte Distanzen zurückgeben
	}
	
	/**
	 * Aufgabe 3.1
	 * Ermittelung des normierten (maximale Länge der Zeichenketten) Levensthein-Abstandes zwischen zwei Zeichenketten
	 * @param name1 Die erste Zeichenkette
	 * @param name2 Die zweite Zeichenkette
	 * @return Der normierte Abstand zwischen den beiden Zeichenketten
	 */
	public static double nameDistance(String name1, String name2) {
		Double d = (double) new Levenshtein().calculateDistance(name1, name2);
		return d/Math.max(name1.length(), name2.length());
	}
	
	/**
	 * Aufgabe 3.2
	 * Ermittelung des normierten (|a-b|/(a+b) Abstandes zwischen zwei Positionen
	 * @param pos1 Die erste Position
	 * @param pos2 Die zweite Position
	 * @return Der normierte Abstand zwischen zwei Positionen
	 */
	public static double posDistance(int pos1, int pos2) {
		return //TODO: |a-b|/(a+b) zurückgeben
	}
	
	/**
	 * Aufgabe 4
	 * Ermittelung der Distanz zwischen zwei Relationen
	 * @param t1 Die erste Relation
	 * @param t2 Die zweite Relation
	 * @return Der Abstand zwischen beiden Relationen
	 */
	public static double getTableDistance(TableInformation t1, TableInformation t2) {
		String name1 = t1.getName();
		String name2 = t2.getName();
		double d1 = //TODO: Distanz der Relationsnamen via Levensthein-Distanz ermitteln
		
		ArrayList<ColumnInformation> c1 = t1.getColumnInformation();
		ArrayList<ColumnInformation> c2 = t2.getColumnInformation();
		ArrayList<ColumnInformation> c2copy = new ArrayList<ColumnInformation>();
		c2copy.addAll(c2);
		
		double d2 = 0;
		int count = 0;
		for(ColumnInformation ci1: c1) {
			ColumnInformation currentMin = null;
			double currentDistance = 1;
			for(ColumnInformation ci2: c2copy) {
				double distance = getColumnDistance(ci1, ci2);
				//TODO: Spalte mit kleinster Distanz bestimmen
			}
			//TODO: Zähler erhöhen, Distanz ausfsummieren, das aktuell gematchte Attribut entfernen

		}
		return //TODO Rückgabe der Namensähnlichkeit + gemittelter Spaltenähnlichkeit;
	}
	
	/**
	 * Ermittlung der Distanzmatrix der Relationen zweier Schemata
	 * @param schema1 Das erste Schema
	 * @param schema2 Das zweite Schema
	 * @return Eine Matrix (Liste von Liste von Double-Werten) mit Abständen der einzelnen Relationen
	 */
	public static ArrayList<ArrayList<Double>> getDistanceMatrix(ArrayList<TableInformation> schema1, ArrayList<TableInformation> schema2){
		ArrayList<ArrayList<Double>> matrix = new ArrayList<ArrayList<Double>>();
		//TODO Über beide Schemata iterieren und die Distanz zwischen jeder Tabelle bestimmen
		return matrix;
	}
	
	/**
	 * Hilfsfunktion: Schemainformationen zu einzelnen Relationen und deren Attribute (Name, Typ, Länge) via JDBC ermitteln
	 * @param schema Das zu analysierende Schema
	 * @param dbmd Metadaten über die Datenbank
	 * @return Liste mit allen Informationen über eine Relation
	 * @throws SQLException
	 */
	public static ArrayList<TableInformation> getSchemaInformation(String schema, DatabaseMetaData dbmd) throws SQLException{
		ArrayList<TableInformation> scheme = new ArrayList<TableInformation>();		
		ResultSet rs = dbmd.getTables(null, schema, null, new String[] {"TABLE"});
		while (rs.next()) {
			ResultSet resultSet = dbmd.getColumns(null, schema, rs.getString("TABLE_NAME"), null);
			int i = 1;
			ArrayList<ColumnInformation> columns = new ArrayList<ColumnInformation>();
			while (resultSet.next()) {
				String name = resultSet.getString("COLUMN_NAME");
				String type = resultSet.getString("TYPE_NAME");
				int size = resultSet.getInt("COLUMN_SIZE");
				ColumnInformation ci = new ColumnInformation(i, name, type, size);
				columns.add(ci);
				i++;
			}
			TableInformation ti = new TableInformation(rs.getString("TABLE_NAME"), columns);
			scheme.add(ti);
		}
		return scheme;
	}
}
