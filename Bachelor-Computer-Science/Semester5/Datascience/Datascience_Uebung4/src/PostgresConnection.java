import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class PostgresConnection {

	public static Connection getConnection() throws ClassNotFoundException, SQLException{
		Class.forName("org.postgresql.Driver");
		Connection connection = null;
		
		//Variante 1: Informatiknetz direkt oder via VPN
		connection = DriverManager.getConnection("jdbc:postgresql://postgresql.informatik.uni-rostock.de:5432/patch_main", ".",".");
		
		//Variante 2: Mit Putty ins Informatiknetz
		//connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/patch_main", ".",".");
		return connection;
	}
	
}
